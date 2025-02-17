#include <iostream>
using namespace std;

// * * * * * 
// * * * * * 
// * * * * * 
// * * * * * 
// * * * * *
// int main(){
//     for(int i = 0 ;i <5;i++){
//         for(int j = 0 ;j <5;j++){
//             cout << "*" << " ";
//         }   
//         cout << endl;
//     }
// }


// * 
// * *
// * * *
// * * * *
// * * * * *
// int main(){
//     for(int i = 1 ; i <6;i++){
//         for(int j = 0 ; j<i ;j++){
//             cout << "*" << " ";
//         }
//         cout << endl;
//     }
// }


// 1 
// 1 2
// 1 2 3
// 1 2 3 4
// 1 2 3 4 5
// int main(){
//     for(int i = 1 ; i <6;i++){
//         for(int j = 1 ; j<=i ;j++){
//             cout << j << " ";
//         }
//         cout << endl;
//     }
// }


// 1 
// 2 2
// 3 3 3
// 4 4 4 4
// 5 5 5 5 5

// int main(){
//     for(int i = 1 ; i <6;i++){
//         for(int j = 1 ; j<=i ;j++){
//             cout << i << " ";
//         }
//         cout << endl;
//     }
// }

// * * * * * 
// * * * * 
// * * * 
// * * 
// * 
// int main(){
//     for(int i = 5 ; i > 0;i--){
//         for(int j = i;j>0;j--){
//             cout << "*" << " ";
//         }
//         cout << endl;
//     }
// }

// 1 2 3 4 5 
// 1 2 3 4
// 1 2 3
// 1 2
// 1


// int main(){
//     for(int i = 6 ; i > 0;i--){
//         for(int j = 1 ; j < i;j++){
//             cout << j << " ";
//         }   
//         cout << endl;
//     }
//     return 0;
// }


// *    
// ***   
// *****  
// ******* 
// *********
// int n = 5;
// for(int i = 0 ; i < n ; i++){
//     for(int j = 0 ; j < n-i-1 ; j++){
//         cout << " ";
//     }
//     for(int k = 0;k<i*2+1;k++){
//         cout << "*";
//     }
//     for(int j = 0 ; j < n-i-1 ; j++){
//         cout << " ";
//     }
//     cout << endl;
// }


// ********* 
// *******
//  *****
//   ***
//    *
// int n = 5;
//     for(int i = 0 ; i < n ; i++){
//         for(int j = 0 ; j <= i ; j++ ){
//             cout << " ";
//         }
//         for(int k = 0 ; k < 2*n - (2*i+1) ; k++){
//             cout << "*";
//         }
//         for(int j = 0 ; j <= i ; j++ ){
//             cout << " ";
//         }
//         cout << endl;
//     }

// *
// **
// ***
// ****
// *****
// ******
// *****
// ****
// ***
// **
// *

// int n = 6;
//     for(int i = 0 ; i < n*2 -1 ; i++){
//         if(i < 5){
//             for(int j = 0 ; j <= i; j ++ ){
//                 cout << "*";
//             }
//         }else{
//             for(int j = 2*n-i-1 ; j > 0; j -- ){
//                 cout << "*";
//             }
//         }
//         cout << endl;
//     }


int main(){
    int n = 6;
    for(int i = 0 ; i < n*2 -1 ; i++){
        if(i < 5){
            for(int j = 0 ; j <= i; j ++ ){
                cout << "*";
            }
        }else{
            for(int j = 2*n-i-1 ; j > 0; j -- ){
                cout << "*";
            }
        }
        cout << endl;
    }

}