#include <iostream>

class AdjacencyMatrix {
	private:
		int nvertex;
		int** matrix;
	public:
		AdjacencyMatrix(int nvertex) {
			this->nvertex = nvertex;
			matrix = new int*[nvertex];
			for(int i = 0; i < nvertex; i++) {
				matrix[i] = new int[nvertex];
				for(int j = 0; j < nvertex; j++) {
					matrix[i][j] = 0;
                                }
			}
		}
		~AdjacencyMatrix() {
			for(int i = 0; i < nvertex; i++) {
                                delete[] matrix[i];
                        } 
			delete[] matrix;
		}
		int num_vertex() {
			return nvertex;
		}
		void create_arist(int i, int j) {
			matrix[i][j] = 1;
			matrix[j][i] = 1;
		}
		void remove_arist(int i, int j) {
			matrix[i][j] = 0;
			matrix[j][i] = 0;
		}
		void print_matrix() {
			std::cout << "\t";
			for(int j = 0; j < nvertex; j++)
			       std::cout << j << '\t';
			std::cout << std::endl;	
			for(int i = 0; i < nvertex; i++) {
				std::cout << i << "\t";
				for(int j = 0; j < nvertex; j++) {
					std::cout << matrix[i][j] << "\t"; 
				}
				std::cout << std::endl;
			}
		}
};

int main() {
	AdjacencyMatrix m(5);
	m.create_arist(0,4);
	m.print_matrix();
}
