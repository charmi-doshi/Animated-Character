## Goal
Build a character animation system from scratch while getting hands-on experience with C++ and SDL3

## Learnings

- C++20 OOP & Composition : Designed decoupled Player, Animator, and HUD components instead of coupling responsibilities into a single class.
- Frame-Independent Game Loops : Implemented delta-time updates with high-resolution SDL timing for consistent movement and animation across different frame rates.
- Manual Memory Management & RAII : Worked with resource ownership, destructors, dynamic allocation, and deleted copy operations to prevent leaks and invalid object lifetimes.
- 2D Rendering Pipeline : Built a basic SDL3 rendering pipeline for textures, sprites, transparency, and fallback rendering.
- Performance Monitoring : Implemented a smoothed FPS system using a circular buffer for frame-time sampling.
