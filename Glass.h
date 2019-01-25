#ifndef GLASS_H
#define GLASS_H

#include "definitions.h"
#include <iostream>
#include <fstream>

using namespace std;

extern int Global_Best_Objective_Function;
extern  int DibujarOpenGL();
class GlassPlate;
 class GlassRectangle;
 class GlassStack;
 class GlassItem;
class GlassDefect;
class Glass_Corte;


typedef std::pair <int, int> ParInt;

typedef  std::list< GlassDefect > LGlassDefect;

typedef std::pair< std::pair< int, int >, std::pair< int, int > >  Coordinates;

typedef std::list< GlassRectangle > LRectangles;




class Glass
{
public:

	GlassPlate * plate; // List of solution used plates.

	GlassNode *sol_items; // List of solution nodes.
	GlassStack *stacks; // List of batch stacks.
	GlassItem *items; // List of batch items.

	LGlassDefect DefectsPlate[PLATES_NBR_LIMIT]; //List of defects per plate
	LGlassDefect DefectsPlateRotate[PLATES_NBR_LIMIT]; //List of defects per plate

	std::list< GlassPlate > G_Plate_Sol; // List of solution used plates.

										 /// Optimization Parameters file Parser

	unsigned int active_log = 1;
	unsigned int active_log_error = 0;// Once log file is generated this var will be cleared.
//	std::ofstream log_file; // Reference to log file.

//	std::ofstream statistics_file; // Reference to statisticsLog file.
//	std::ofstream statistics_ins_file;
	bool opened_file = true; // Boolean to test if one of needed files (batch, solution, defects and optimization parameters) was not opened.

	std::string file_idx ; // To save used file index (Normal mode).
	std::string testPath ; // To save path according to chosen test.
	std::string instance ; // To save used file index (Test mode).

	unsigned int s_idx = 0; // Solution index, used precise where to insert solution node in sol_items array.
	unsigned int plates_nbr = 0; // Save solution used plates number.
	unsigned int stack_nbr = 0; // Save batch stack number.
	unsigned int plates_list[PLATES_NBR_LIMIT][2];   // Save number of nodes for each plate used in user solution.
													 // plates_list[X][Y]:   X dimension contains plates Ids list
													 //                      Y dimension contains number of nodes of plate X
													 //change
	unsigned int plate_defect[100][2];

	unsigned int lines_nbr = 0; // csv file lines number.
	unsigned int node_nbr = 0; // Solution file nodes number.
	unsigned int useful_node = 0; // Solution useful nodes number (node not a branch or waste or residual).
	unsigned int branch_node = 0; // Solution branch nodes number
	unsigned int residual_node = 0; // Solution residual nodes number.
	unsigned int waste_node = 0; // Solution waste nodes number.
	unsigned int batch_items = 0; // Batch items number.
	unsigned int constraint_error = 0; // Success constraint, combination of solution's occured errors (refer to main.h to find errors list).
	unsigned int defects_nbr = 0; // Defects file defects number.

	unsigned int total_waste = 0; // Sum of wasted area.
	unsigned int total_useful = 0; // Sum of used area.

	int max_cut_stage = 0; // Solution max used cut stage.

	unsigned int Total_area = 0;
	unsigned int plate_nbr_limit = 0; // To save Optimization parameters plate number limit constraint.
	unsigned int plate_w = 0; // To save Optimization parameters plate's length constraint.
	unsigned int plate_h = 0; // To save Optimization parameters plate's width constraint.
	unsigned int min1Cut = 0; // To save Optimization parameters cut 1 & 2 min1Cut constraint.
	unsigned int min2Cut = 0; // To save Optimization parameters cut 1 & 2 min2Cut constraint.
	unsigned int max1Cut = 0; // To save Optimization parameters cut 1 & 2 max1Cut  constraint.
	unsigned int waste_min = 0; // To save Optimization parameters cut 1 & 2 minWasteWidth constraint.

	unsigned int success = 1;

	int MinDimensionPieza = MAXIMUM_INT;
	int MaxMinDimensionPieza = 0;
	int MinDimensionPieza_Inicial = MAXIMUM_INT;
	int MaxMinDimensionPieza_Inicial = 0;
	string name_instance; //name to the instance
	bool deterministic = false; //Variable to indicate if we use a deterministic version
	bool joint_items = false; //variable to indicate if we joint items equals
	bool silent = true; //Do not show anything 
	int Para_Random = 2;
	int Start_strip = 0;
	int MoreThanOne = 0;
	unsigned int G_iter_veces = 0;
	int G_Time = 0;
	bool G_Classic = false;
	bool G_Rotate = false;
	int TrozoBin = 0;
	struct timeb G_Time_Initial ;
	

	unsigned int Total_area_used = 0;//Suma of used area partial
	unsigned int Total_width_bin = 0;
	unsigned int Max_First_Bin = 0;
	unsigned int Objective_function = 0;
	unsigned int Partial_objective_function = 1000;

	unsigned int Inicio = 0;
	unsigned int Plates = 0;
	unsigned int NumberOfPlate = 0;
	bool G_finish_instant =true;
	int SizeOfBeam = 1;
	int Hilo = 0;
	double Utilization = 0;
	double Best_Utilization = 0;
	int iter_finish = 0;
	std::list< GlassNodeB > ListaNodosBeam;
	std::list< GlassNodeB > ListaNodosBeam_Utilization2;
	std::list< GlassNodeB > ListaNodosBeam_G_children;
	std::list< GlassNodeB > ListaNodosBeam_G_children_Classical;
	unsigned int seed = 1;
	int G_Iterations = 1;
	int G_Size_width = 1;
	unsigned int Partial_objective_function_List = MAXIMUM_INT; //Least value of Partial_objective_function int percentaje per thousand
	unsigned int Max_List_Nodos_Beam_Per_Nodo = 10;
	unsigned int Max_List_Nodos_Beam = 100;
	unsigned int Max_List_Nodos_Beam_Global = 50;
	unsigned int Max_List_Nodos_Beam_Global_Double = 50;
	unsigned int Max_List_Nodos_Beam_Global_Utilization = 50;
	unsigned int Max_List_Nodos_Beam_Global_Global = 50;
	unsigned int Initial_Objective_function = 0;
	unsigned int Best_Objective_function = MAXIMUM_INT;
	unsigned int Best_Objective_function_Thread = MAXIMUM_INT;
	unsigned int Best_plates_nbr = 100;
	unsigned int Best_iter = 0;
	unsigned int G_iteraciones = 1500;
	unsigned int G_level = 0;
	unsigned int G_iter = 0;
	unsigned int G_children = 0;
	unsigned int NumberOfPlates = 100;
	unsigned int RestOfLastPlate = 0;
	unsigned int Best_Width_First_Rotate = 0;
	bool one_item_each = false;
	bool draw_solution = true;
	unsigned int node_id = 0;
	unsigned int rect_id = 0;
	std::list< GlassRsol>  G_Rsol_Items;
	std::list< GlassRsol>  G_Best_Rsol_Items;
	bool wider = false;
	bool higher = false;
	bool To_the_Top = false;
	int MinAncho = MAXIMUM_INT;
	int cont_plates = 0;

	int Max_children_Level = 10;
	int G_rotated_nodes = 0;
	//We have a vector por each stack an we save the item
	std::vector< std::vector < int > > G_Matrix_Items;
	// the size of this vector is the number of stacks, the first number is 
	//which is the first item possible to place
	std::vector< int > G_Vector_Stacks;
	std::vector< bool > G_Vector_Items;
	std::vector< int > G_Random_Stacks;
	std::vector< Glass_Corte > G_Rotate_Solution;
	std::list< Glass_Corte > G_Solution_Rotated;
	std::list< Glass_Corte > G_Best_Solution_Rotated;
	int G_Total_Nodes = 0;
	int G_type_strip = 1;
	int G_tipo_lista = 0;
	int G_Repeticiones = 1;
	int G_bad_solutions = 0;
	std::vector< int > G_Vector_Size_Stacks;
	bool G_first_time_node = false;

	//Parallel
	std::vector< std::vector< std::vector < int > > >  GP_Matrix_Items;
	std::vector < std::vector< int > > GP_Vector_Stacks;
	std::vector < std::vector< bool > >GP_Vector_Items;
	std::vector < std::vector< int > > GP_Random_Stacks;

	std::vector < std::vector< int > > GP_Vector_Size_Stacks;

	//List with each coordinate is the item, the x's position, y's position, top corner x position, top corner y position
	std::vector< std::vector < int> > G_Positions_Items;
	//List with each coordinate is the item, the x's position, y's position, top corner x position, top corner y position
	std::vector< std::vector < int> > G_Best_Positions_Items;
	int m_id=0;
	//functions copy
	Glass();
	Glass(int i);
	Glass(string i);
	Glass(string i,int,int );
	virtual ~Glass();

	//functions
	bool BeamSearch(int Hilo,int );
	bool BeamSearchRotate( int Hilo, int);
	void TransformarSolucionSimetrica(string filep,bool);
	void CorteHorizontalSimetry(int ini, int fin);
	void CorteVerticalSimetry(int ini, int fin);

	bool BeamSearchParallel();
	std::pair<int, int > ItemGreater(int max_width, int max_height, short int tipo);
	std::pair<int, int > ItemGreaterRN(GlassRectangle &R);
	bool CheckSolution();
	
	bool CheckSolutionEnd();
	bool CheckSolutionPartial();
	void PrintProblem(string problem);
	Coordinates ItemGreaterRN_J(GlassRectangle &R);
	void PutRSolType(std::list< GlassRsol > ::iterator  &it, int toright, int toup);
	void PutRSolTypeCurrent(std::list< GlassRsol > ::iterator  &it, int toright, int toup);
	Coordinates ItemGreaterRNRandom_J(GlassRectangle &R);
	std::pair<int, int > ItemGreaterRNRandom(GlassRectangle &R);
	std::pair<int, int > ItemGreaterRNAreaV(GlassRectangle &R);
	std::pair<int, int > ItemGreaterRNAreaH(GlassRectangle &R);
	std::pair<int, int > ItemGreaterRNH(GlassRectangle &R);
	std::pair<int, int > ItemGreaterRNV(GlassRectangle &R);
	Coordinates ItemGreaterRNH_J(GlassRectangle &);
	Coordinates ItemGreaterRNAreaV_J(GlassRectangle &);
	Coordinates ItemGreaterRNV_J(GlassRectangle &);
	int MinimaDimension(GlassRectangle &Rect, GlassRsol &Sol);
	Coordinates ComputeLowestRectangle_H(GlassRectangle &R);
	Coordinates ComputeLowestRectangle_V(GlassRectangle &);
	int TallestBeginning(std::list< GlassRsol > ::iterator  &, int, int);

	int BottomBeginning(std::list< GlassRsol > ::iterator  &it, int toright, int tall);
	Coordinates PlaceItem(Coordinates p, GlassRectangle &Rect);
	Coordinates PlaceItem(std::pair<int, int> p, GlassRectangle &Rect);
	bool NotEqualCurrent(GlassNodeB &node2);
	bool AlgoritmoRandom();
	bool Dominated(GlassNodeB &node2);
	void createNodeB(GlassNodeB &node3);
	bool InsertPartialSolution();
	bool InsertPartialSolutionClassical();
	bool SecondFilter();
	void SelectByGlobalObjectiveFunction();
	bool RemoveDominated();
	void RecoverPartialSolution(int i);
	void BetterSolution(int a);
	void SymetricProblem();
	void DibujarChosen();
	void SaveSolution();
	//EN Linux poner return

	void DibujarOpenGL() {
		return;
	};
	
	
	//From a list of pieces, create the solution
	void MakeFileTextSolution(string path);
	int ThereIsSomethingInThisStrip(std::list< GlassRsol > ::iterator  &it, int ini, int fin, int fin_strip);



	//Look up into the list an item down of this
	bool NothingDown(std::vector< std::vector <int> > ::iterator  &);

	//Look up into the list an item left of this
	bool NothingLeft(std::vector< std::vector <int> > ::iterator  &, int);

	//The biggest piece in the horizontal strip
	int  NothingUp(std::vector< std::vector <int> > ::iterator  &it, int from, int tosize);

	int  NextRightBottom(std::vector< std::vector <int> > ::iterator  &it, int toright);

	//somtehing up -1 or the value
	int  NothingUp(std::vector< std::vector <int> > ::iterator  &it, int toright);

	int  NextRight(std::vector< std::vector <int> > ::iterator  &it, int toright);

	int  NextRight(std::list< GlassRsol > ::iterator  &it, int toright, int toup);

	bool NextPut(std::list< GlassRsol > ::reverse_iterator  itk, int WID);

	int  TallestInTheStrip(std::vector< std::vector <int> > ::iterator  &it, int toright);

	int  BottomInTheStripNext(std::list< GlassRsol > ::iterator  &it, int toright);
	//Look up into the list an item down of this
	bool NothingDown(std::list< GlassRsol > ::iterator  &);

	//Look up into the list an item left of this
	bool NothingLeft(std::list< GlassRsol > ::iterator  &, int);

	//The biggest piece in the horizontal strip
	int  NothingUp(std::list< GlassRsol > ::iterator  &it, int from, int tosize);

	int  NextRightBottom(std::list< GlassRsol > ::iterator  &it, int toright);

	//somtehing up -1 or the value
	int  NothingUp(std::list< GlassRsol > ::iterator  &it, int toright);

	int  NextRight(std::list< GlassRsol > ::iterator  &it, int toright);
	int  NextRightCurrent(std::list< GlassRsol > ::iterator  &it, int toright);
	int  TallestInTheStrip(std::list< GlassRsol > ::iterator  &it, int toright);

	void ChangeRectanglesSimmetry(int maxWidth);
	void WriteWastesBottom(FILE *files, int x, int y, int X, int Y, int px, int py, int pX, int pY, int pla, int pa, int &nod, int pa_cut);
	void WriteWastesLeft(FILE *files, int x, int y, int X, int Y, int px, int py, int pX, int pY, int pla, int pa, int &nod, int pa_cut);
	void WriteWastes(FILE *files, int x, int y, int X, int Y, int px, int py, int pX, int pY, int pla, int &pa, int &nod, int &pa_cut);
	void PushWastesBottom( int x, int y, int X, int Y, int px, int py, int pX, int pY, int pla, int pa, int &nod, int pa_cut);
	void PushWastesLeft( int x, int y, int X, int Y, int px, int py, int pX, int pY, int pla, int pa, int &nod, int pa_cut);
	void PushWastes( int x, int y, int X, int Y, int px, int py, int pX, int pY, int pla, int &pa, int &nod, int &pa_cut);

	void ChangeWidthRectangles();
	void  ChangeBase(int width);
	void  ChangeUnder(GlassRectangle &, int);
	bool Overlap(std::list<GlassRectangle>& lista, int x, int y, int X, int Y);
//	void ChangeRectangles(int Right, int Up, GlassRectangle &Rect, std::list< GlassRectangle> &lista, std::list< GlassDefect > ldefects);
	void Randomize(std::vector<int>& lista);
	bool NotOther(std::list<GlassRsol>::iterator & it, int fin, int inicio, int toright);
	bool AllStartsAtTheSameHeightInTheStrip(GlassRectangle &Rect);
	//Set how many are equals
	void JointItems();
	std::pair<int, int> ComputeIfBetterToDoChange(GlassRectangle & Rect, Coordinates & pitem);
	//Create Matrix
	void CreateMatrix();

	//Initialize Matrix
	void RestartMatrix();

	//Update Min Dimension
	void UpdateMinDimension(std::pair<int, int>);

	//Change position where place
	bool ChangePositionToPlace(GlassRectangle &R);

	//Write the solution to draw
	void WriteSolution(string filep = "temp2.txt");

	//Write the solution 
	void WritePlates();

	//Check Overlap rectangle with its defects
	bool Overlap(int x1, int y1, int X1, int Y1, GlassRectangle &R);
	bool Overlap(int x1, int y1, int X1, int Y1);
	void ChangeRectangles(int Right, int Up, GlassRectangle &Rect, std::list< GlassRectangle> &lista, std::list< GlassDefect > ldefects);

	//Choose
	std::pair<int, int > ItemGreaterHeight(int max_width, int max_height);
	std::pair<int, int > ItemGreaterWidth(int max_width, int max_height);

	bool AlgoritmoDeterminista();
	bool AsignarItemsPlate(GlassRectangle &);
	int AsignarItemsPlate_J(GlassRectangle &);

	GlassRectangle * AsignarRectangulo(GlassRectangle &rectangulo);

	//Erase an element from the list
	void EraseRectangleFromList(LRectangles &lista, GlassRectangle &R);

	void EraseRectangleFromList(LRectangles &lista, int id_rect);

	void ChangeRectangleFromList(LRectangles &, int);
	bool   CheckChangesToTheTop(int, int);
	bool   MakeFeasibleToTheTop(int, int);
	bool BeamSearch();
	void FinishSolutions();
	void FinishSolution();
	void PutObjectiveFunction(int);
	void InsertClassical();
	void InsertarSolucionGlobal();
	bool InsertPartialSolutionGlobal(GlassNodeB);
	inline int Distancia(GlassDefect &D, int x1, int y1)
	{
		return (((D.Getpos_x() - x1)*(D.Getpos_x() - x1)) + ((D.Getpos_y() - y1)*(D.Getpos_y() - y1)));
	}
	int randomfunc_1(int j);
	inline bool Overlap(int x1, int y1, int X1, int Y1, int x2, int y2, int X2, int Y2);
	inline bool Wastemin(int x1, int y1, int X1, int Y1, GlassRectangle & R);

	//Originals

	int parseOptimizationParams(string path);


	/// Batch file Parser
	int parseBatch(string path);

	/// Batch file Parser
	void parseBatchJointItems(string path);

	/// Solution file Parser
	int parseSolution(string path);


	/// Defects file Parser
	int parseDefects(string path);


	/// Data Structure Builder
	void buildDataStructure(GlassNode *node);


	/// Data Structure Builder
	void checkSuccessors(GlassNode *node, GlassNode *sol_items, int plate_id, GlassNode &parent, int c_end, int index);


	/// Create Plate Instance
	int createPlate(string *token, int p);


	/// Create Node Instance
	int createNode(GlassNode * node, string *token, int p);


	/// Create Item Instance
	int createItem(GlassItem *items, string *token, int p);


	/// Create Item Joint Instance
	bool createItemJoint(GlassItem *items, string *token, int p);

	/// Display Plates Area Usage
	void displayPlatesAreaUsage(void);


	/// Verify Identity & Sequence constraints
	void verifyIdt_Sequence(void);


	/// Verify Dimensions constraint
	void verifyDimensions(void);


	/// Verify Dimensions constraint of a node successors
	void checkSuccDimensions(GlassNode parent);


	/// Verify Defects overlap constraint
	void verifyDefects(void);


	/// Verify Item Production constraint
	void verifyItemProduction(void);


	/// Create statisticsLog log file
	void statisticsLog(void);

	/// List violated constraints.
	void violatedConstraints(void);

	///Old funciton verify
	int verify_main(void);

	//statisticsItemsDefects
	void statistics(void);
	int verify_main_interactive(void);

	unsigned int explore(GlassNode n);
	bool NoItemBetweenTallMin(std::list< GlassRsol > ::iterator  &it, int toright, int tall);
	int  NextRightTop(std::list< GlassRsol > ::iterator  &it, int toright);
	//Parallel

	void CreateMatrixP(int Iter);
	bool BeamSearchParallel(int Iterations, int SizeOfBea, int Many, int Hil, int seed_id);
	void LevelEvaluation(int level,  GlassNodeB  &nodo);
	void RecoverPartialSolution(GlassNodeB &nodo);
	void DoubleEvaluation();
	bool InsertPartialSolutionGlobalUtil2(GlassNodeB node);
	bool NotInTheList(GlassNodeB &nodo);
	void ChangeDimensionsSimetry(Glass_Corte &d);
	int MaxWidthLastPiece(std::list< GlassRsol >  &lista_temp);
	int MinWidthLastPiece(std::list< GlassRsol >  &lista_temp);
	int get_random(const int & min, const int & max);
	void EscribirSolutionRotated(string filep, std::list< Glass_Corte> &);
	bool EstaYaPuesto(int);
};


#endif // GLASS_H