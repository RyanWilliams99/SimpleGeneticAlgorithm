#include <stdlib.h>
#include <iostream>
#include <time.h>

const int N = 10;
const int P = 50;


typedef struct {
	int gene[N];
	int fitness;
} individual;


int GenerateFitnessValues(individual ind)
{

	int fitness = 0;
	for (int i = 0; i < N; i++) {
		if (ind.gene[i] == 1)
			fitness += 1;
	}

	return fitness;

}


//void GenerateOffspring()
//{
//	for (int i = 0; i < P; i++) {
//		int parent1 = rand() % P;
//		int parent2 = rand() % P;
//		if (population[parent1].fitness > population[parent2].fitness)
//			offspring[i] = population[parent1];
//		else
//			offspring[i] = population[parent2]
//	}
//}

void PrintPopulationFitness(individual population[P])
{

	int t = 0;

	std::cout << "Population Fitness" << std::endl;

	for (int i = 0; i < P; i++)
	{
		std::cout << population[i].fitness << " ";

		t = t + population[i].fitness;

	}

	std::cout << " Total Fitness - " << t << std::endl << std::endl;


}


int main()
{ 

	//5 Generations
	for (int i = 0; i < 5; ++i) {
		
		individual population[P];
		individual offspring[P];



		for (int i = 0; i < P; i++)
		{
			for (int j = 0; j < N; j++)
			{
				population[i].gene[j] = rand() % 2;
			}
			population[i].fitness = 0;
		}

		for (int i = 0; i < P; i++)
		{
			population[i].fitness = GenerateFitnessValues(population[i]);
		}


		PrintPopulationFitness(population);

		for (int i = 0; i < P; i++) {
			int parent1 = rand() % P;
			int parent2 = rand() % P;
			if (population[parent1].fitness > population[parent2].fitness)
				offspring[i] = population[parent1];
			else
				offspring[i] = population[parent2];
		}

		PrintPopulationFitness(offspring);

	}
	
	return 0;

}