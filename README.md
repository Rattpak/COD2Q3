## COD2Q3
Barebones COD4/5 map file to Quake 3 map file format.
 - Only supports brushes without attributes (can't be detail, non-colliding, etc)
 - Only supports "lightmap_gray" (default). Press Shift + L in radiant to change if needed
 - Does not support prefabs (just stamp them in radiant)
 - Does not support curves, entities, or terrain patches (yet)
 - Works with [TrenchBroom](https://trenchbroom.github.io/).
 - Works with [Qodot](https://qodotplugin.github.io/)
 
## Usage
To use the program, compile and run the code and copy/drag your .map file onto it.
The output will be in the same directory as input file and will append _q3 at the end of the file name
