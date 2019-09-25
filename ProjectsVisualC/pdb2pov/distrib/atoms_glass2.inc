/*
   Object and texture declarations for some stock Atoms, using VDW radii
   These atoms are glass texture to allow one to see through surface
   atoms.

   Author:
	Eric G. Suchanek, Ph.D.
*/

/* Must include:
#include "colors.inc"
#include "shapes.inc"
#include "textures.inc"
  and either atoms_cpk.inc or atoms_covalent.inc...
*/
#declare Atoms_Inc_Temp = version

#version 2.0

#declare my_glass_finish = finish {
      ambient 0.1
      diffuse 0.1
      specular 0.8
      reflection 0.1
      refraction 0.9
      ior 1.15
      roughness 0.0003
      phong 1 phong_size 400
}

#declare Glass_N = 
 texture
   { pigment
     { color Blue filter 0.98}
     finish { my_glass_finish }
   }

#declare Glass_C = 
 texture
   { pigment
     { color Green filter 0.98}
     finish { my_glass_finish }
   }

#declare Glass_S = 
 texture
   { pigment
     { color Yellow filter 0.98}
     finish { my_glass_finish }
   }

#declare Glass_Ca = 
 texture
   { pigment
     { color DarkPurple filter 0.98}
     finish { my_glass_finish }
   }

#declare Glass_O = 
 texture
   { pigment
     { color Red filter 0.98}
     finish { my_glass_finish }
   }

#declare Glass_H = 
 texture
   { pigment
     { color VLightGrey filter 0.98}
     finish { my_glass_finish }
   }

#declare Glass_Fe = 
 texture
   { pigment
     { color Gold filter 0.98}
     finish { my_glass_finish }
   }

#declare Clear_Atom = texture {
   pigment { color red 1.0 green 1.0 blue 1.0 filter 0.98}
   finish { my_glass_finish }
}

#declare Atom_Glass_N = object {
	sphere {<0.0, 0.0, 0.0> N_RAD }
	texture { Glass_N }
}

#declare Atom_Glass_C = object {
	sphere {<0.0, 0.0, 0.0> C_RAD }
	texture { Glass_C }
}

#declare Atom_Glass_O = object {
	sphere {<0.0, 0.0, 0.0> O_RAD }
	texture { Glass_O }
}

#declare Atom_Glass_S = object {
	sphere {<0.0, 0.0, 0.0> S_RAD }
	texture { Glass_S }
}

#declare Atom_Glass_P = object {
	sphere {<0.0, 0.0, 0.0> P_RAD }
	texture { Glass_S }
}

#declare Atom_Glass_Ca = object {
	sphere {<0.0, 0.0, 0.0> CA_RAD }
	texture { Glass_Ca }
	pigment { color DarkPurple quick_color DarkPurple}
}

#declare Atom_Glass_H = object {
	sphere {<0.0, 0.0, 0.0> H_RAD }
	texture { Glass_H }
}

#declare Atom_Glass_Fe = object {
	sphere {<0.0, 0.0, 0.0> FE_RAD }
	texture { Glass_Fe }
}

