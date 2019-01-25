# Roadef_UCLM_UV_2018
Source Code Team 17 Roadef 2018 

Universidad de Castilla-La Mancha
Universidad de Valencia

We used -fopenmp and standard c++



If you want to use, use the standard parameters of the challenge are indicated in:

http://www.roadef.org/challenge/2018/en/finalSubmission.php

You have to put the globalparameters in a folder called dataset_B/

For the challenge:

#!/bin/bash 
#SBATCH -c 4 
#SBATCH --ntasks=1 
#SBATCH --cpus-per-task=4 export 
OMP_NUM_THREADS=8 
./challengeSG -p instancias_A_New/A1 -name 1 -s 2 -t 360 -o instancias_A_New/A1solution_360.txt > ./output1.log 
