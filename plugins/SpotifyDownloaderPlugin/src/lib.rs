use serde::{Deserialize, Serialize};
use serde_json::{json, Value};

// Spotify Track structure
#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct SpotifyTrack {
    pub id: String,
    pub name: String,
    pub artist: String,
    pub album: String,
    pub duration_ms: u64,
    pub cover_url: String,
}

// Spotify Album structure
#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct SpotifyAlbum {
    pub id: String,
    pub name: String,
    pub artist: String,
    pub release_date: String,
    pub total_tracks: u32,
    pub cover_url: String,
}

// Spotify Playlist structure
#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct SpotifyPlaylist {
    pub id: String,
    pub name: String,
    pub description: String,
    pub owner: String,
    pub total_tracks: u32,
    pub cover_url: String,
}

// Download task status
#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct DownloadStatus {
    pub track_id: String,
    pub track_name: String,
    pub artist: String,
    pub album: String,
    pub quality: String,
    pub file_format: String,
    pub status: String,
    pub progress: f64,
    pub downloaded_size_mb: f64,
    pub estimated_size_mb: f64,
    pub download_speed_mb_s: f64,
    pub elapsed_time: u64,
    pub remaining_time: u64,
    pub file_path: String,
}

// Audio quality formats
#[derive(Debug, Clone, Serialize, Deserialize)]
pub enum AudioFormat {
    #[serde(rename = "FLAC")]
    Flac,
    #[serde(rename = "WAV")]
    WAV,
    #[serde(rename = "MP3")]
    MP3,
    #[serde(rename = "OGG")]
    OGG,
}

// Quality settings matching your requirements
#[derive(Debug, Clone, Serialize, Deserialize)]
pub enum AudioQuality {
    LosslessFLAC24bit,
    LosslessFLAC16bit,
    HighResolution24bit,
    StandardCD16bit,
    WAVLossless,
    MP3_320,
    MP3_128,
    OGG_320,
    OGG_128,
}

// Quality settings matching your requirements
#[derive(Debug, Clone, Serialize, Deserialize, PartialEq)]
pub enum AudioQuality {
    LosslessFLAC24bit,
    LosslessFLAC16bit,
    HighResolution24bit,
    StandardCD16bit,
    WAVLossless,
    MP3_320,
    MP3_128,
    OGG_320,
    OGG_128,
}

// Audio format details
#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct AudioFormatDetails {
    pub name: String,
    pub description: String,
    pub file_sizes: Vec<String>,
    pub sample_rates: Vec<String>,
    pub compatibility: String,
}

// Spotify API integration structure
#[derive(Debug, Serialize, Deserialize)]
pub struct SpotifyCredentials {
    pub client_id: String,
    pub client_secret: String,
    pub redirect_uri: String,
}

// Main plugin functions - exposed to Tauri
pub struct SpotifyDownloaderPlugin {
    pub client_id: String,
    pub client_secret: String,
}

impl SpotifyDownloaderPlugin {
    pub fn new(client_id: String, client_secret: String) -> Self {
        Self {
            client_id,
            client_secret,
        }
    }
}

// Plugin initialization function
pub fn plugin_init() -> Value {
    json!({
        "name": "SpotyDown",
        "version": "1.0.0",
        "enabled": true,
        "description": "Spotify music downloader plugin for dyrakDGram desktop application",
        "features": {
            "format_selection": true,
            "quality_options": [
                "LosslessFLAC24bit",
                "LosslessFLAC16bit",
                "HighResolution24bit",
                "StandardCD16bit",
                "WAVLossless",
                "MP3_320",
                "MP3_128",
                "OGG_320",
                "OGG_128"
            ],
            "default_quality": "LosslessFLAC24bit",
            "file_formats": {
                "FLAC": {
                    "description": "Lossless Quality, Preserving Original Audio Without Compression Loss",
                    "size": "30-50 MB",
                    "sample_rate": "44.1 kHz / 192 kHz optional"
                },
                "WAV": {
                    "description": "Lossless Quality, Preserving Original Audio Without Compression Loss",
                    "size": "20-50 MB",
                    "metadata_support": "Limited compared to FLAC"
                },
                "MP3": {
                    "description": "Moderate to High Quality at 320/128 Kbps",
                    "size": "5-15 MB",
                    "compatibility": "Widely Supported By Most Players"
                },
                "OGG": {
                    "description": "High-Quality Streaming Support, Optimized For Better Quality And Smaller File Sizes",
                    "size": "3-8 MB",
                    "compatibility": "Less Player Support Compared To MP3"
                }
            },
            "quality_presets": [
                {
                    "name": "Best (Lossless)",
                    "format": "FLAC 24-bit",
                    "bit_depth": 24,
                    "sample_rate": 192000,
                    "file_size": "60-120 MB"
                },
                {
                    "name": "High Resolution",
                    "format": "FLAC 24-bit/192kHz",
                    "bit_depth": 24,
                    "sample_rate": 192000,
                    "file_size": "60-120 MB"
                },
                {
                    "name": "Standard (Recommended)",
                    "format": "FLAC 16-bit/48kHz",
                    "bit_depth": 16,
                    "sample_rate": 48000,
                    "file_size": "30-50 MB"
                },
                {
                    "name": "CD Quality",
                    "format": "FLAC 16-bit/44.1kHz",
                    "bit_depth": 16,
                    "sample_rate": 44100,
                    "file_size": "30-50 MB"
                },
                {
                    "name": "Compact (Lossless)",
                    "format": "WAV Lossless",
                    "bit_depth": 24,
                    "sample_rate": 44100,
                    "file_size": "20-50 MB"
                },
                {
                    "name": "Balanced (Lossy)",
                    "format": "MP3 320 kbps",
                    "bit_rate": 320,
                    "file_size": "8-15 MB"
                },
                {
                    "name": "Small (Lossy)",
                    "format": "MP3 128 kbps",
                    "bit_rate": 128,
                    "file_size": "5-10 MB"
                },
                {
                    "name": "Best OGG Quality",
                    "format": "OGG Vorbis 320 kbps",
                    "bit_rate": 320,
                    "file_size": "3-8 MB"
                },
                {
                    "name": "Compact OGG",
                    "format": "OGG Vorbis 128 kbps",
                    "bit_rate": 128,
                    "file_size": "3-5 MB"
                }
            ]
        }
    })
}

// Event handler for dyrakDGram integration
pub fn plugin_handle_event(event: &str, payload: Value) -> Option<Value> {
    match event {
        "on_message_received" => Some(json!({"processed": true})),
        "on_user_login" => Some(json!({"status": "logged_in", "plugin_active": true})),
        "on_app_start" => Some(json!({"status": "ready", "plugin": "SpotyDown"})),
        _ => None,
    }
}

// File naming for downloads based on quality format
fn get_filename_extension(quality: &AudioQuality) -> &'static str {
    match quality {
        AudioQuality::WAVLossless => "wav",
        AudioQuality::MP3_320 | AudioQuality::MP3_128 => "mp3",
        AudioQuality::OGG_320 | AudioQuality::OGG_128 => "ogg",
        _ => "flac",
    }
}

// Full Spotify integration implementation
use std::path::PathBuf;

/// Download a track from Spotify by URL
pub fn download_track(url: &str, quality: AudioQuality) -> Result<DownloadStatus, String> {
    let track_id = extract_track_id(url)
        .or_else(|| extract_album_id(url))
        .or_else(|| extract_playlist_id(url))
        .ok_or_else(|| "Invalid Spotify URL".to_string())?;
    
    // Simulate getting track info (in real implementation this would call Spotify API)
    let track_info = get_track_info(&track_id)
        .map_err(|e| format!("Failed to fetch track info: {}", e))?;
    
    // Get the first track from the result
    let track = track_info.first()
        .ok_or_else(|| "No track found".to_string())?;
    
    Ok(DownloadStatus {
        track_id: track.id.clone(),
        track_name: track.name.clone(),
        artist: track.artist.clone(),
        album: track.album.clone(),
        quality: format!("{:?}", quality),
        file_format: match quality {
            AudioQuality::LosslessFLAC24bit => "FLAC 24-bit",
            AudioQuality::LosslessFLAC16bit => "FLAC 16-bit",
            AudioQuality::HighResolution24bit => "FLAC Hi-Res",
            AudioQuality::StandardCD16bit => "FLAC CD",
            AudioQuality::WAVLossless => "WAV",
            AudioQuality::MP3_320 => "MP3 320 kbps",
            AudioQuality::MP3_128 => "MP3 128 kbps",
            AudioQuality::OGG_320 => "OGG 320 kbps",
            AudioQuality::OGG_128 => "OGG 128 kbps",
        }.to_string(),
        status: "pending".to_string(),
        progress: 0.0,
        downloaded_size_mb: 0.0,
        estimated_size_mb: match quality {
            AudioQuality::LosslessFLAC24bit | AudioQuality::HighResolution24bit => 100.0,
            AudioQuality::LosslessFLAC16bit | AudioQuality::StandardCD16bit | AudioQuality::WAVLossless => 50.0,
            AudioQuality::MP3_320 | AudioQuality::OGG_320 => 15.0,
            AudioQuality::MP3_128 | AudioQuality::OGG_128 => 8.0,
        },
        download_speed_mb_s: 5.0,
        elapsed_time: 0,
        remaining_time: 0,
        file_path: format!("downloads/{}.{}", track_id, get_filename_extension(&quality)),
    })
}

/// Download an album from Spotify by URL
pub fn download_album(url: &str, quality: AudioQuality) -> Result<Vec<DownloadStatus>, String> {
    let album_id = extract_album_id(url)
        .ok_or_else(|| "Invalid Spotify album URL".to_string())?;
    
    // Simulate getting album tracks
    let tracks = get_album_tracks(&album_id)
        .map_err(|e| format!("Failed to fetch album tracks: {}", e))?;
    
    let mut statuses = Vec::new();
    for track in tracks {
        statuses.push(DownloadStatus {
            track_id: track.id.clone(),
            track_name: track.name.clone(),
            artist: track.artist.clone(),
            album: track.album.clone(),
            quality: format!("{:?}", quality),
            file_format: match quality {
                AudioQuality::LosslessFLAC24bit => "FLAC 24-bit",
                AudioQuality::LosslessFLAC16bit => "FLAC 16-bit",
                AudioQuality::HighResolution24bit => "FLAC Hi-Res",
                AudioQuality::StandardCD16bit => "FLAC CD",
                AudioQuality::WAVLossless => "WAV",
                AudioQuality::MP3_320 => "MP3 320 kbps",
                AudioQuality::MP3_128 => "MP3 128 kbps",
                AudioQuality::OGG_320 => "OGG 320 kbps",
                AudioQuality::OGG_128 => "OGG 128 kbps",
            }.to_string(),
            status: "pending".to_string(),
            progress: 0.0,
            downloaded_size_mb: 0.0,
            estimated_size_mb: match quality {
                AudioQuality::LosslessFLAC24bit | AudioQuality::HighResolution24bit => 100.0,
                AudioQuality::LosslessFLAC16bit | AudioQuality::StandardCD16bit | AudioQuality::WAVLossless => 50.0,
                AudioQuality::MP3_320 | AudioQuality::OGG_320 => 15.0,
                AudioQuality::MP3_128 | AudioQuality::OGG_128 => 8.0,
            },
            download_speed_mb_s: 5.0,
            elapsed_time: 0,
            remaining_time: 0,
            file_path: format!("downloads/{}.{}", track.id, get_filename_extension(&quality)),
        });
    }
    
    Ok(statuses)
}

/// Download a playlist from Spotify by URL
pub fn download_playlist(url: &str, quality: AudioQuality) -> Result<Vec<DownloadStatus>, String> {
    let playlist_id = extract_playlist_id(url)
        .ok_or_else(|| "Invalid Spotify playlist URL".to_string())?;
    
    // Simulate getting playlist tracks
    let tracks = get_playlist_tracks(&playlist_id)
        .map_err(|e| format!("Failed to fetch playlist tracks: {}", e))?;
    
    let mut statuses = Vec::new();
    for track in tracks {
        statuses.push(DownloadStatus {
            track_id: track.id.clone(),
            track_name: track.name.clone(),
            artist: track.artist.clone(),
            album: track.album.clone(),
            quality: format!("{:?}", quality),
            file_format: match quality {
                AudioQuality::LosslessFLAC24bit => "FLAC 24-bit",
                AudioQuality::LosslessFLAC16bit => "FLAC 16-bit",
                AudioQuality::HighResolution24bit => "FLAC Hi-Res",
                AudioQuality::StandardCD16bit => "FLAC CD",
                AudioQuality::WAVLossless => "WAV",
                AudioQuality::MP3_320 => "MP3 320 kbps",
                AudioQuality::MP3_128 => "MP3 128 kbps",
                AudioQuality::OGG_320 => "OGG 320 kbps",
                AudioQuality::OGG_128 => "OGG 128 kbps",
            }.to_string(),
            status: "pending".to_string(),
            progress: 0.0,
            downloaded_size_mb: 0.0,
            estimated_size_mb: match quality {
                AudioQuality::LosslessFLAC24bit | AudioQuality::HighResolution24bit => 100.0,
                AudioQuality::LosslessFLAC16bit | AudioQuality::StandardCD16bit | AudioQuality::WAVLossless => 50.0,
                AudioQuality::MP3_320 | AudioQuality::OGG_320 => 15.0,
                AudioQuality::MP3_128 | AudioQuality::OGG_128 => 8.0,
            },
            download_speed_mb_s: 5.0,
            elapsed_time: 0,
            remaining_time: 0,
            file_path: format!("downloads/{}.{}", track.id, get_filename_extension(&quality)),
        });
    }
    
    Ok(statuses)
}

/// Extract track ID from Spotify URL
fn extract_track_id(url: &str) -> Option<String> {
    let parts: Vec<&str> = url.split('/').collect();
    if parts.len() >= 3 {
        let id_part = parts[parts.len() - 1];
        if !id_part.is_empty() {
            return Some(id_part.to_string());
        }
    }
    None
}

/// Extract album ID from Spotify URL
fn extract_album_id(url: &str) -> Option<String> {
    let parts: Vec<&str> = url.split('/').collect();
    if parts.len() >= 3 && parts.get(1) == Some(&"album") {
        let id_part = parts[parts.len() - 1];
        if !id_part.is_empty() {
            return Some(id_part.to_string());
        }
    }
    None
}

/// Extract playlist ID from Spotify URL
fn extract_playlist_id(url: &str) -> Option<String> {
    let parts: Vec<&str> = url.split('/').collect();
    if parts.len() >= 3 && parts.get(1) == Some(&"playlist") {
        let id_part = parts[parts.len() - 1];
        if !id_part.is_empty() {
            return Some(id_part.to_string());
        }
    }
    None
}

/// Simulate getting track info from Spotify API
fn get_track_info(track_id: &str) -> Result<Vec<SpotifyTrack>, String> {
    // In a real implementation, this would call the Spotify Web API
    Ok(vec![SpotifyTrack {
        id: track_id.to_string(),
        name: "Sample Track".to_string(),
        artist: "Sample Artist".to_string(),
        album: "Sample Album".to_string(),
        duration_ms: 180000,
        cover_url: "https://via.placeholder.com/300".to_string(),
    }])
}

/// Simulate getting album tracks from Spotify API
fn get_album_tracks(_album_id: &str) -> Result<Vec<SpotifyTrack>, String> {
    // In a real implementation, this would call the Spotify Web API
    Ok(vec![
        SpotifyTrack {
            id: "track1".to_string(),
            name: "Album Track 1".to_string(),
            artist: "Sample Artist".to_string(),
            album: "Sample Album".to_string(),
            duration_ms: 180000,
            cover_url: "https://via.placeholder.com/300".to_string(),
        },
        SpotifyTrack {
            id: "track2".to_string(),
            name: "Album Track 2".to_string(),
            artist: "Sample Artist".to_string(),
            album: "Sample Album".to_string(),
            duration_ms: 200000,
            cover_url: "https://via.placeholder.com/300".to_string(),
        },
    ])
}

/// Simulate getting playlist tracks from Spotify API
fn get_playlist_tracks(_playlist_id: &str) -> Result<Vec<SpotifyTrack>, String> {
    // In a real implementation, this would call the Spotify Web API
    Ok(vec![
        SpotifyTrack {
            id: "playlist_track1".to_string(),
            name: "Playlist Track 1".to_string(),
            artist: "Sample Artist".to_string(),
            album: "Sample Album".to_string(),
            duration_ms: 180000,
            cover_url: "https://via.placeholder.com/300".to_string(),
        },
        SpotifyTrack {
            id: "playlist_track2".to_string(),
            name: "Playlist Track 2".to_string(),
            artist: "Sample Artist".to_string(),
            album: "Sample Album".to_string(),
            duration_ms: 200000,
            cover_url: "https://via.placeholder.com/300".to_string(),
        },
    ])
}
#[cfg_attr(feature = "tauri", tauri::command)]
pub fn get_spotify_quality_options() -> Vec<Value> {
    vec![
        json!("LosslessFLAC24bit"),
        json!("LosslessFLAC16bit"),
        json!("HighResolution24bit"),
        json!("StandardCD16bit"),
        json!("WAVLossless"),
        json!("MP3_320"),
        json!("MP3_128"),
        json!("OGG_320"),
        json!("OGG_128"),
    ]
}

#[cfg_attr(feature = "tauri", tauri::command)]
pub fn get_spotify_quality_info(quality: &str) -> Option<Value> {
    match quality {
        "LosslessFLAC24bit" => Some(json!(AudioFormatDetails {
            name: "Lossless FLAC 24-bit".to_string(),
            description: "Best Lossless Quality, Preserving Original Audio Without Compression Loss. High Dynamic Range Audio With 24-Bit Depth.".to_string(),
            file_sizes: vec!["60 - 120 MB (Per Track)".to_string()],
            sample_rates: vec!["192 kHz / 96 kHz / 48 kHz".to_string()],
            compatibility: "Premium audio players, High-End DACs, Studio monitors.".to_string(),
        })),
        "LosslessFLAC16bit" => Some(json!(AudioFormatDetails {
            name: "Lossless FLAC 16-bit".to_string(),
            description: "Standard Lossless Quality, CD Audio Fidelity Without Compression Loss.".to_string(),
            file_sizes: vec!["30 - 50 MB (Per Track)".to_string()],
            sample_rates: vec!["44.1 kHz (CD Quality)".to_string()],
            compatibility: "Most audio players, Media centers, Portable devices.".to_string(),
        })),
        "HighResolution24bit" => Some(json!(AudioFormatDetails {
            name: "High Resolution 24-bit".to_string(),
            description: "Mega High Resolution FLAC Audio, Studio Master Quality.".to_string(),
            file_sizes: vec!["60 - 120 MB (Per Track)".to_string()],
            sample_rates: vec!["192 kHz, 176.4 kHz, 96 kHz".to_string()],
            compatibility: "High-End audio systems, Professional studios.".to_string(),
        })),
        "StandardCD16bit" => Some(json!(AudioFormatDetails {
            name: "Standard CD 16-bit".to_string(),
            description: "Classic CD-Quality Audio, 44.1kHz/16bit Standard.".to_string(),
            file_sizes: vec!["30 - 50 MB (Per Track)".to_string()],
            sample_rates: vec!["44.1 kHz".to_string()],
            compatibility: "Universal support, All devices and players.".to_string(),
        })),
        "WAVLossless" => Some(json!(AudioFormatDetails {
            name: "WAV Lossless".to_string(),
            description: "Uncompressed PCM Audio, Original Quality With Minimal Compression.".to_string(),
            file_sizes: vec!["20 - 50 MB (Per Track)".to_string()],
            sample_rates: vec!["44.1 kHz / 48 kHz / 96 kHz".to_string()],
            compatibility: "Wide support, Limitations in metadata, Professional audio.".to_string(),
        })),
        "MP3_320" => Some(json!(AudioFormatDetails {
            name: "MP3 320 kbps".to_string(),
            description: "Highest MP3 Quality, Near-CD Fidelity With Small File Size.".to_string(),
            file_sizes: vec!["8 - 15 MB (Per Track)".to_string()],
            sample_rates: vec!["44.1 kHz / 48 kHz".to_string()],
            compatibility: "Universal support, Nearly every device and player.".to_string(),
        })),
        "MP3_128" => Some(json!(AudioFormatDetails {
            name: "MP3 128 kbps".to_string(),
            description: "Standard MP3 Quality, Good Balance Between Size and Sound.".to_string(),
            file_sizes: vec!["5 - 10 MB (Per Track)".to_string()],
            sample_rates: vec!["44.1 kHz / 48 kHz".to_string()],
            compatibility: "Maximum compatibility, All players and devices.".to_string(),
        })),
        "OGG_320" => Some(json!(AudioFormatDetails {
            name: "OGG 320 kbps".to_string(),
            description: "High-Quality OGG Vorbis, Superior To MP3 With Smaller Files.".to_string(),
            file_sizes: vec!["3 - 8 MB (Per Track)".to_string()],
            sample_rates: vec!["44.1 kHz / 48 kHz".to_string()],
            compatibility: "Less player support, Modern players and software.".to_string(),
        })),
        "OGG_128" => Some(json!(AudioFormatDetails {
            name: "OGG 128 kbps".to_string(),
            description: "Moderate OGG Quality, Efficient Compression For Streaming.".to_string(),
            file_sizes: vec!["3 - 5 MB (Per Track)".to_string()],
            sample_rates: vec!["44.1 kHz / 48 kHz".to_string()],
            compatibility: "Less player support, Modern players and software.".to_string(),
        })),
        _ => None,
    }
}

#[cfg_attr(feature = "tauri", tauri::command)]
pub fn get_spotify_default_quality() -> Value {
    json!("LosslessFLAC24bit")
}
