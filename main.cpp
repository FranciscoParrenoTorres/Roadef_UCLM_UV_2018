
/*
 * Francisco Parreño Torres
 UCLM

 */

#include "definitions.h"
#include "Glass.h"
#include <omp.h>


int Global_Best_Objective_Function = MAXIMUM_INT;// 11266923; //2329354

// int  Global_Best_Objective_Function = 2976090;
//int Global_Best_Objective_Function = 2308734;//// 1551385;// 1551385; 3617251



/*
int get_random(const int & min, const int & max) {
	static thread_local std::mt19937 generator(1);
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(generator);
}*/

int main(int argc, char **argv)
{
	
	string file_to_read,file_to_write,batchPath, solutionPath, defectsPath, optParamsPath, file_idx2;
	int TeamId=0,seed=1, Seconds=0;
	int Iter = 10;
	//Procesamiento de los parametros
	
	if ((argc > 2) && (argc % 2 == 1)) 
	{ //Se comprueba que haya pares de argumentos (y al menos un par)

		while (argc > 1)
		{
			if (strcmp(argv[1], "-t") == 0)
			{
				//Tiempo
				sscanf(argv[2], "%d", &Seconds);
			}
			else if (strcmp(argv[1], "-p") == 0)
			{
				//File to read
				file_to_read=argv[2];

			}
			else if (strcmp(argv[1], "-o") == 0)
			{
				file_to_write = argv[2];
			}
			else if (strcmp(argv[1], "-s") == 0)
			{
				sscanf(argv[2], "%d", &seed);
			}
			else if (strcmp(argv[1], "-name") == 0)
			{
				sscanf(argv[2], "%d", &TeamId);
			}
			else if (strcmp(argv[1], "-iter") == 0)
			{
				sscanf(argv[2], "%d", &Iter);
			}
			argc -= 2;
			argv += 2;

		}
	}
	if (argc == 2)
	{
		printf("Team 17");
		return 17;
	}
	srand(seed);
		

		const int seedId = seed, maxSeconds = (Seconds-5);

	file_idx2 = file_to_read;

	batchPath = file_idx2 + "_batch.csv";
	solutionPath =  file_idx2 + "_solution.csv";
	defectsPath =  file_idx2 + "_defects.csv";
    optParamsPath = PATH_TO_INSTANCES "global_param.csv";
	


	struct timeb time_final,time_initial;
	ftime(&time_initial);
	const struct timeb time_ini = time_initial;

	int nThreads=omp_get_max_threads();
	//linux change to 8
	omp_set_num_threads(8);
	


	std::vector< Glass >  Problemas;
	const int Number_Of_Iterations = 100;

	for (int i = 0; i <= Number_Of_Iterations; i++)
	{

		

		Glass Problema(file_to_read, i,seed);
		//REVISAR TODO
		Problema.G_Rotate = false;
//		if (get_aleatorio(0,4)<=0 && (i>12))
	//		Problema.G_Rotate = true;


		Problema.G_Repeticiones = Iter;
		Problema.G_Classic = true;
		Problema.name_instance = file_to_read;
		Problema.G_Time = maxSeconds;
		Problema.G_Time_Initial = time_ini;
		Problema.active_log =false ;
		Problema.active_log_error = false;
		Problema.parseBatch(batchPath);
		Problema.parseDefects(defectsPath);
		if (Problema.batch_items < 30 )
			Problema.G_iteraciones = 2000;
		if (Problema.batch_items > 60)
			Problema.G_iteraciones = 1000;
		if (Problema.batch_items > 300 || Problema.stack_nbr > 60)
			Problema.G_iteraciones = 800;
		if (Problema.batch_items > 600 || Problema.stack_nbr > 120)
			Problema.G_iteraciones = 600;
		if (Problema.batch_items > 900 || Problema.stack_nbr > 180)
			Problema.G_iteraciones = 400;
		Problema.parseOptimizationParams(optParamsPath);
		Problema.G_iter_veces = 0;
		if (get_aleatorio(0,10)>=9)
			Problema.G_Classic = true;
		else
		Problema.G_Classic = false;
		if (get_aleatorio(0, 3) == 0)
			Problema.G_finish_instant = true;
		else
			Problema.G_finish_instant = false;
		//MultiStart();
		Problema.statistics();


		Problema.CreateMatrix();

		Problema.JointItems();

		Problema.one_item_each = false;
		Problema.draw_solution = true;

		Problema.deterministic = false;
		Problema.G_iteraciones = (Problema.G_iteraciones * 10) / 10;


		Problema.G_Iterations= (i / 4) + (i % 4) + 1;
		Problema.G_Size_width= (i / 4) + (i % 4) + 1;


		if ((i + 1) % 4 == 2) Problema.G_tipo_lista = 3;

	

		Problemas.push_back(Problema);
	

	}
	

	
#pragma omp parallel  
	{



#pragma omp for schedule(static,1) nowait




		for (int Global_Iter = 0; Global_Iter <= Number_Of_Iterations; Global_Iter++)
		{




			struct timeb  time_ini2;

			ftime(&time_ini2);
			double tmp_first2 = ((double)((time_ini2.time - time_ini.time) * 1000 + time_ini2.millitm - time_ini.millitm)) / 1000;
			if (tmp_first2 < maxSeconds)
			{

				struct timeb  time_ini21;
				ftime(&time_ini21);




				if (Problemas[Global_Iter].active_log_error)
					printf("\nTipo Nivel %d Thread %d Iter \t%d\n", Problemas[Global_Iter].G_type_strip, omp_get_thread_num(), Global_Iter);


				if (Problemas[Global_Iter].G_Rotate==true)
				Problemas[Global_Iter].BeamSearchRotate(omp_get_thread_num(), seedId);
				else
					Problemas[Global_Iter].BeamSearch(  omp_get_thread_num(), seedId);

				ftime(&time_ini2);
				tmp_first2 = ((double)((time_ini2.time - time_ini21.time) * 1000 + time_ini2.millitm - time_ini21.millitm)) / 1000;
				if (Problemas[Global_Iter].active_log_error) printf("\nTiempo %f Thread %d Iter \t%d\n", tmp_first2, omp_get_thread_num(), Global_Iter);
				if (Problemas[Global_Iter].active_log_error) printf("\nTiempo2 %f Thread %d Iter \t%d\n", tmp_first2, omp_get_thread_num(), Global_Iter);

			}

		}
	}
	
	std::list< GlassRsol > Global_Best_Solution;
	std::list< Glass_Corte> Global_Best_Solution_Rotated;
	int Iter_Best = -1;//;__max((1200 / tmp_first) / 2, 2);
					  //	int Global_Iter = 0;
	int maxLevel = 0;
	int maxIter = 0;
	int Level_Best_Solution = 0;
	int Iterations = 0;
	bool Rotate = false;
	int Tipo_Lista = 0;
	int Type_Strip = 1;
	bool Classic = false;
	bool FInstant = false;
	for (int Global_Iter = 0; Global_Iter <= Number_Of_Iterations; Global_Iter++)
	{
		if (Problemas[Global_Iter].G_iter_veces != 0)
			maxIter = Global_Iter;
		else
			continue;
		if (Problemas[Global_Iter].Best_Objective_function_Thread == Global_Best_Objective_Function)
		{
			if (Iter_Best == -1)
			{
				Global_Best_Solution = Problemas[Global_Iter].G_Best_Rsol_Items;
				Iter_Best = Global_Iter;
				Level_Best_Solution = Problemas[Global_Iter].Best_iter;
				Iterations=Problemas[Global_Iter].G_Iterations;
				Rotate= Problemas[Global_Iter].G_Rotate;
				if (Rotate == true)
					Global_Best_Solution_Rotated = Problemas[Global_Iter].G_Best_Solution_Rotated;
				Tipo_Lista= Problemas[Global_Iter].G_tipo_lista;
				Type_Strip = Problemas[Global_Iter].G_type_strip;
				Classic= Problemas[Global_Iter].G_Classic;
				FInstant = Problemas[Global_Iter].G_finish_instant;
			}
		}

		if (Problemas[Global_Iter].G_level > maxLevel)
			maxLevel = Problemas[Global_Iter].G_level;
	}
	if (Problemas[0].active_log_error) printf("Best_Solution %d", Global_Best_Objective_Function);


	//	printf("here1");
	Problemas[0].Best_Objective_function = Global_Best_Objective_Function;
	Problemas[0].G_Best_Rsol_Items = Global_Best_Solution;
	//	Problem.MakeFileTextSolution(file_idx2 + "_solution" + std::to_string(maxSeconds) + "_" + std::to_string(nThreads) + ".csv");
	if (Rotate == false)
		Problemas[0].MakeFileTextSolution(file_to_write);
	else
		Problemas[0].EscribirSolutionRotated(file_to_write, Global_Best_Solution_Rotated);
	//	printf("here2");



	ftime(&time_final);
	double tmp_first = ((double)((time_final.time - time_ini.time) * 1000 + time_final.millitm - time_ini.millitm)) / 1000;

	//	Size = max((1000 / tmp_first) , 2);
	double tmp_second = 0;



	printf( "%s Time Ini %f   Best %d  Global Iter Best %d Max Iter %d MaxLevel %d Level Best Solution %d Iter %d Rotate %d Iterations %d Tipo Lista %d Tipo Strip %d Classic %d Finstant %d Iter %d\n", file_idx2.c_str(), tmp_first, Global_Best_Objective_Function, Iter_Best, maxIter, maxLevel, Level_Best_Solution, Iter,Rotate,Iterations,Tipo_Lista,Type_Strip,Classic,FInstant,Iter);

	if (!Problemas[0].opened_file)
		return EXIT_FAILURE;
	return EXIT_SUCCESS;

}

