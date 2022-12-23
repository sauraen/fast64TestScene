# fast64TestScene

Test Ocarina of Time scene for fast64.

This repository does not contain any Nintendo-copyrighted code or assets. All
textures and other assets were already in the public domain or have been created
and are hereby dedicated to the public domain.

## To use

- Open this scene in Blender with fast64 (latest version or a particular branch).
- Export the scene over your preferred scene in the decomp (choose a "normal"
  scene which does not have any hard-coded attributes in the game, such as
  Link's house).
- **Replace scene render function XX with the contents of `render_function.c`.**
- Build the ROM.
- Run the ROM on a flashcart on a real N64 or on an accurate LLE emulator.
- Enter the scene and ensure that all the "paintings" are visible and match
  their appearance in Blender.
