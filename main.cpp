//
//  main.cpp
//  WalmartSWEQ
//
//  Created by Ronit Pattanayak on 3/13/22.
//

#include <iostream>
#include <getopt.h> // CL Tools
#include <vector>
#include <map>
#include <algorithm>    // std::min


using namespace std;

class Assign{
private:
    vector<vector<bool>> filled; // stores offset
    uint32_t capacity = 200;
    uint32_t numRows = 10;
    uint32_t numCols = 20;
    vector<bool> rows_visited;
    vector<uint32_t> fill_order = {5,7,3,1,9,6,4,8,2,0}; // Prioritize one row difference as much as possible
    
   /* map<int,bool> row_filled = { {5,false}, {7,false}, {3,false}, {1,false}, {9,false}, {6,false}, {4,false}, {8,false} , {2,false}, {0,false}};*/
    map<uint32_t,char> row_map = {{0,'A'},{1,'B'}, {2,'C'}, {3,'D'}, {4,'E'}, {5,'F'}, {6,'G'}, {7,'H'}, {8,'I'}, {9,'J'} };
    
  //  map<int, int> visited; // key is row, and value is offset from
    
public:
    void init_map(){
        filled.resize(10, vector<bool>(20,false)); // 10 x 20 memo vector, all initially false
      // TODO: handle reservations with more than 10 customers
        rows_visited.resize(10,false); // initially nothing has been filled
    }
    
    void fill_map(uint32_t seats){
        capacity -= seats;
        if(capacity < 0){ // Error checking if more than 200 seats in total requested
            exit(1);
        }
        for(uint32_t i = 0; i < numRows; i++){
            if(!rows_visited[fill_order[i]]){
                uint32_t row = fill_order[i];
                rows_visited[row] = true;
                if(seats > 14){ // place in middle columns of theater if possible first
                    
                    if(!filled[row][10]){ // all possible arrangements require column 5 to be open
                        uint32_t start_idx = (numCols - seats) / 2;
                        uint32_t bound = start_idx + seats;
                        for(uint32_t i = 0; i < numCols; i++){
                            filled[row][i] = true;
                            if(start_idx < bound){
                                cout << row_map[row] << start_idx + 1 << ",";
                                start_idx++;
                            }
                        }
                        cout << "\n";
                        break;
                    }
                }
                for(uint32_t j = 0; j < numCols; j++){ // TODO: Switch between fill from right and left, make more efficient using map?
                    if(!filled[row][j]){
                        if(j <= numCols - seats){ // can fit in column
                            uint32_t bound = min(numCols, j + seats + 3); // + 3 accounts for buffer
                            for(uint32_t k = j; k < bound; k++){
                                filled[row][k] = true;
                                if(k < j + seats){
                                    cout << row_map[row] << k + 1 << ",";
                                }
                            }
                            //std::cout << std::setfill('0') << std::setw(5) << 25;
                            cout << "\n";
                            break;
                        }
                    }
                }
                break;
            }
        }
        
        // Code only reaches here when all rows filled :
        // ------- Larger Test Cases Logic ------- //
        
        
    }
    void output(){
        
    }
};

int main() {
    Assign a;
    a.init_map();
    string temp;
    while(cin >> temp){
        int num_seats;
        cin >> num_seats;
        if(num_seats <= 0){ // invalid input
            exit(1);
        }
        cout << temp << " ";
        uint32_t param = (uint32_t) num_seats;
        a.fill_map(param);
    }
    a.output();
    return 0;
}
