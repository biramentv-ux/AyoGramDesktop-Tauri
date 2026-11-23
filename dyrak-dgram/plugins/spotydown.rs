// SpotyDown - Audio Processing
use tauri::{command, AppBuilder};
use std::path::PathBuf;

#[derive(Debug)]
pub struct AudioFile {
    pub name: String,
    pub path: PathBuf,
}

#[command]
fn get_downloaded_audio() -> Vec<AudioFile> {
    vec![AudioFile { name: "Song.mp3".to_string(), path: PathBuf::from("/downloads/Song.mp3") }]
}

pub struct SpotyDownPlugin;

impl SpotyDownPlugin {
    pub fn init(_app: &mut AppBuilder) {
        println!("SpotyDown Plugin initialized");
    }
}
