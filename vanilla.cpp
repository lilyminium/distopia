//
// Created by Richard Gowers on 8/13/20.
//

#include <math.h>

void VanillaCalcBonds(const float* coords1,
                      const float* coords2,
                      const float* box,
                      unsigned int nvals,
                      float* output) {
    for (unsigned int i=0; i<nvals; ++i) {
        float r2 = 0.0;
        for (unsigned char j=0; j<3; ++j) {
            float rij = coords1[i * 3 + j] - coords2[i * 3 + j];
            float adj = round(rij / box[j]);
            rij -= adj * box[j];

            r2 += rij * rij;
        }
        *output++ = sqrtf(r2);
    }
}

void VanillaCalcBondsIdx(const float* coords,
                         const unsigned int* idx,
                         const float* box,
                         unsigned int nvals,
                         float* output) {
  for (unsigned int i=0; i<nvals; ++i) {
    unsigned int a = idx[i*2];
    unsigned int b = idx[i*2 + 1];
    float r2 = 0.0;
    for (unsigned char j=0; j<3; ++j) {
      float rij = coords[a*3 + j] - coords[b*3 + j];
      float adj = round(rij / box[j]);
      rij -= adj * box[j];

      r2 += rij * rij;
    }
    *output++ = sqrtf(r2);
  }
}