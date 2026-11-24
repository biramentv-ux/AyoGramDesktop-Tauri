// Build script for dyrakDGram
fn main() {
    // Run Tauri build process
    tauri_build::build();
    
    // Print initialization messages for all plugins
    println!("cargo:rustc-env=TUIR_BUILD=true");
    println!("cargo:rerun-if-changed=src-tauri/src/plugins");
}
