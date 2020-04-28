#include <iostream>
#include <vector>
#include <math.h>
#include <numeric>
#include <omp.h>
#include "FractalCreator.hpp"

int const nTrials = 10;
int const skipTrials = 3;

int main()
{
    const int HEIGHT = 600;
    const int WIDTH = 800;

    std::vector<double> processing_times;
    printf("\nImage Size: %d x %d \n\n", WIDTH, HEIGHT);
    printf("\033[1m%5s %15s\n", "Step", "Time (ms)");

    for (int iTrial = 0; iTrial < nTrials; iTrial++)
      {
        FractalCreator myFractal(WIDTH, HEIGHT);
        myFractal.addZoom(Zoom(250, 290, 4.0/WIDTH));
        double const t0 = omp_get_wtime();
        myFractal.calculateIterations();
        myFractal.drawFractal();
        double const t1 = omp_get_wtime();
        double const tms = (t1 - t0)*1.0e3;
        processing_times.push_back(tms);
        myFractal.writeBitMap("../test.bmp");
        printf("%5d %15.3f%s\n", iTrial+1, tms, (iTrial+1<=skipTrials?"*":""));
      }
    printf("-----------------------------------------------------\n");
    printf("\033[1m%s\033[0m%15.3f\n", "Average Performance: ",
           ((double)std::accumulate(processing_times.begin() + skipTrials, processing_times.end(), 0)
           /(processing_times.size() - skipTrials)));
    return 0;
}
