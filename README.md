## COD2Q3
Barebones COD4/5 map file to Quake 3 map file format.
 - Only supports brushes without attributes (can't be detail, non-colliding, etc)
 - Does not support prefabs (just stamp them in radiant)
 - Does not support curves or entities (yet)
 - Textures will be mapped at 0.5 on X, Y, and Z. Will be changed in future
 - Works with [TrenchBroom](https://trenchbroom.github.io/).
 
## Usage
To use the program, run the exe and copy/drag your .map file onto it.
The output will be in the same directory as input file and will append _q3 at the end of the file name
