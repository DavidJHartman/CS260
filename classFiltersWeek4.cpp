#include <GL/freeglut.h>
#include <iostream>
#include <cmath>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;


// consts
const float SCALE = 0.5;
const int ARESX = 990;
const int ARESY = 743;
const int WRESX = ARESX * SCALE;
const int WRESY = ARESY * SCALE;



// functions
void display();
void fill(unsigned char arr[ARESY][ARESX][3]);
void print(unsigned char arr[ARESY][ARESX][3]);
void bright(unsigned char arr[ARESY][ARESX][3], int n);
void contrast(unsigned char arr[ARESY][ARESX][3], double n);
void blur(unsigned char arr[ARESY][ARESX][3]);
unsigned char inRange(int n);
unsigned char nbrAvg(unsigned char arr[ARESY][ARESX][3], int r, int c, int color);
void sharpen(unsigned char arr[ARESY][ARESX][3]);
unsigned char nbrSharp(unsigned char arr[ARESY][ARESX][3], int r, int c, int color);
void bubblizer(unsigned char arr[ARESY][ARESX][3], int n);


int main(int argc, char** argv) {
    // set up displays and mode (we won't change this!)
	glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    
	// set window size
	glutInitWindowSize (WRESX, WRESY); 
    
	// set window position on screen
	glutInitWindowPosition (0, 0);

	// set window title
    glutCreateWindow ("test");
    
    // set the display function to the one we made below
	glutDisplayFunc(display);
	
	// required to make the thing go 
    glutMainLoop();

	// exit
    return 0;
}


void display() {
	//  clear all pixels
    glClear (GL_COLOR_BUFFER_BIT);

	// make and fill in array
	static unsigned char arr[ARESY][ARESX][3] = {0};
	fill(arr);
	bright(arr, 0);
	
	//contrast(arr, 0.01);
	//contrast(arr, -1);
    
    bubblizer(arr, 15);

	// resize the array to the size of the window RES
	glPixelZoom((float)WRESX/ARESX, (float)WRESY/ARESY);
	
	// unpack wrong??
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glPixelStorei(GL_UNPACK_SKIP_PIXELS, 0);
	glPixelStorei(GL_UNPACK_SKIP_ROWS, 0);

	// draw the array to the screen
	glDrawPixels(ARESX, ARESY, GL_RGB, GL_UNSIGNED_BYTE, arr);

	// start processing buffered OpenGL routines 
    glFlush ();
}


void blur(unsigned char arr[ARESY][ARESX][3]) {
	// make temp array
	unsigned char temp[ARESY][ARESX][3];

	// go through original array
	for(int r = 1; r < ARESY-1; r++) {
		for(int c = 1; c < ARESX-1; c++) {
			for(int color = 0; color < 3; color++) {
				int avg = 0;
				avg += arr[r-1][c-1][color];
				avg += arr[r-1][c][color];
				avg += arr[r-1][c+1][color];
				avg += arr[r][c-1][color];
				avg += arr[r][c][color];
				avg += arr[r][c+1][color];
				avg += arr[r+1][c-1][color];
				avg += arr[r+1][c][color];
				avg += arr[r+1][c+1][color];
				temp[r][c][color] = avg / 9.0;
			}
		}
	}
	
	// put temp back into arr
	for(int r = 1; r < ARESY-1; r++) {
		for(int c = 1; c < ARESX-1; c++) {
			for(int color = 0; color < 3; color++) {
				arr[r][c][color] = temp[r][c][color];
			}
		}
	}
}


void bright(unsigned char arr[ARESY][ARESX][3], int b) {
	for(int r = 0; r < ARESY; r++) {
		for(int c = 0; c < ARESX; c++) {
			arr[r][c][0] = inRange(arr[r][c][0] + b);
			arr[r][c][1] = inRange(arr[r][c][1] + b);
			arr[r][c][2] = inRange(arr[r][c][2] + b);
		}
	}
}


void contrast(unsigned char arr[ARESY][ARESX][3], double n) {
	for(int r = 0; r < ARESY; r++) {
		for(int c = 0; c < ARESX; c++) {
			arr[r][c][0] = inRange((arr[r][c][0]-128) * n + 128);
			arr[r][c][1] = inRange((arr[r][c][1]-128) * n + 128);
			arr[r][c][2] = inRange((arr[r][c][2]-128) * n + 128);
		}
	}
}


void bubblizer(unsigned char arr[ARESY][ARESX][3], int n) {
   srand(time(NULL)); 
    int position[n][2];
    int radius[n];

    for ( int i = 0; i < n; i++ ) {
        position[i][0] = rand()%ARESY;
        position[i][1] = rand()%ARESX;
        radius[i] = rand()%51 + 100;
    }
    for ( int i = 0; i < ARESY; i++ ) {
        for ( int j = 0; j < ARESX; j++ ) {
            
            for (int c = 0; c < n; c++ ) {
                
                int tempy = i - position[c][0];
                int tempx = j - position[c][1];

                if ( sqrt( tempx * tempx + tempy * tempy ) < radius[c] ) {
                    arr[i][j][0] = inRange( arr[i][j][0] / 2 );
                    arr[i][j][1] = inRange( arr[i][j][1] / 2 );
                    arr[i][j][2] = inRange( arr[i][j][2] / 2 );
                    goto bub;
                }

            }
            
            arr[i][j][0] = inRange( arr[i][j][0] * 4.4 );
            arr[i][j][1] = inRange( arr[i][j][1] * 4.4 );
            arr[i][j][2] = inRange( arr[i][j][2] * 4.4 );
            
            bub:;
        }
    }   
    
}



unsigned char inRange(int n) {
	if(n > 255) {
		return 255;
	} else if (n < 0){
		return 0;
	} else {
		return n;
	}
}


void fill(unsigned char arr[ARESY][ARESX][3]) {
	// set up the file
	ifstream file;
	file.open("holi.bmp");
	
	// skip the file header
	file.ignore(54);

	// read the file into arr
	for(int r = 0; r < ARESY; r++) {
		for(int c = 0; c < ARESX; c++) {
			arr[r][c][2] = file.get();
			arr[r][c][1] = file.get();
			arr[r][c][0] = file.get();
		}
			
		// deal with end of line buffer
		if(ARESX*3%4 != 0) {
			for(int i = 0; i < 4 - (ARESX*3)%4; i++) {
				file.get();
			}
		}
	}
}


