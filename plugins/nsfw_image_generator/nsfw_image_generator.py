"""
NSFW Image Generator Plugin for dyrakDGram
Author: biramentv-ux
Description: Uncensored image-to-image generation using Stable Diffusion
"""

import torch
from diffusers import StableDiffusionImg2ImgPipeline, EulerAncestralDiscreteScheduler
from PIL import Image
import os
import requests
from io import BytesIO

class NSFWImageGenerator:
    def __init__(self, model_id="runwayml/stable-diffusion-v1-5", device="cuda"):
        self.model_id = model_id
        self.device = device if torch.cuda.is_available() else "cpu"
        self.pipeline = None
        self._load_model()
    
    def _load_model(self):
        """Load the Stable Diffusion model"""
        try:
            scheduler = EulerAncestralDiscreteScheduler.from_pretrained(
                self.model_id, subfolder="scheduler"
            )
            self.pipeline = StableDiffusionImg2ImgPipeline.from_pretrained(
                self.model_id, scheduler=scheduler, torch_dtype=torch.float16
            )
            self.pipeline = self.pipeline.to(self.device)
            self.is_loaded = True
        except Exception as e:
            print(f"Error loading model: {e}")
            self.is_loaded = False
    
    def generate(
        self, 
        init_image: str, 
        prompt: str, 
        negative_prompt: str = "",
        strength: float = 0.75,
        guidance_scale: float = 7.5,
        num_inference_steps: int = 50,
        seed: int = None
    ) -> str:
        """
        Generate an image using image-to-image
        
        Args:
            init_image: Path to the input image
            prompt: Description of the desired output
            negative_prompt: What to avoid in the output
            strength: How much to transform (0-1)
            guidance_scale: Prompt influence (0-20)
            num_inference_steps: Number of denoising steps
            seed: Random seed for reproducibility
            
        Returns:
            Path to the generated image
        """
        if not self.is_loaded:
            raise RuntimeError("Model not loaded")
        
        # Load input image
        init_image = Image.open(init_image).convert("RGB")
        
        # Generate
        generator = torch.Generator(device=self.device).manual_seed(seed) if seed else None
        
        output = self.pipeline(
            prompt=prompt,
            negative_prompt=negative_prompt,
            init_image=init_image,
            strength=strength,
            guidance_scale=guidance_scale,
            num_inference_steps=num_inference_steps,
            generator=generator
        )
        
        # Save output
        output_path = f"nsfw_output_{seed if seed else 'no_seed'}.png"
        output.images[0].save(output_path)
        return output_path
    
    def generate_batch(
        self,
        init_image: str,
        prompts: list,
        strength: float = 0.75,
        guidance_scale: float = 7.5,
        num_inference_steps: int = 50
    ) -> list:
        """Generate multiple variations"""
        results = []
        for i, prompt in enumerate(prompts):
            try:
                output_path = self.generate(
                    init_image=init_image,
                    prompt=prompt,
                    strength=strength,
                    guidance_scale=guidance_scale,
                    num_inference_steps=num_inference_steps,
                    seed=i
                )
                results.append(output_path)
            except Exception as e:
                print(f"Error generating variation {i}: {e}")
        return results

# Telegram server integration for model loading
def load_model_from_telegram_server() -> bool:
    """Load model configuration from Telegram servers"""
    try:
        response = requests.get(
            "https://api.telegram.org/bot<YOUR_BOT_TOKEN>/getNSFWConfig",
            timeout=10
        )
        if response.status_code == 200:
            config = response.json()
            return True
    except Exception as e:
        print(f"Error loading from Telegram server: {e}")
    return False
