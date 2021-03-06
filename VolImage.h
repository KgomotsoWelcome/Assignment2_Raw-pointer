/*****************************************************************
* Header file for the Volimagedriver
* Author: Kgomotso Welcome
* Date: 25/02/2019
* Date completed: 17/03/2019
******************************************************************/

#ifndef _VolImage_H
#define _VolImage_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace WLCKGO001{

	class VolImage{
	private:  // private members
	
		int width, height, number_images; // width and height of image stack
		vector<unsigned char**> slices; // data for each slice, in order
		
	public: // public members
	
		VolImage(); // default constructor - define in .cpp
		~VolImage(); // destructor - define in .cpp file
			
		// populate the object with images in stack and
		// set member variables define in .cpp
		bool readImages(string baseName);
		
		// compute difference map and write out; define in .cpp
		void diffmap(int sliceI, int sliceJ, string output_prefix);
		
		// extract slice sliceId and write to output - define in .cpp
		void extract(int sliceId, string output_prefix);
		
		void extractCross(int rowId, string output_prefix);

		// number of bytes uses to store image data bytes
		//and pointers (ignore vector<> container, dims etc)
		int volImageSize(void); // define in .cpp
		
		// number of images in the slices vector 
		int numOfImages(void);

		// creates header file for method diffmap, extract and extractRow
		void header(int width, int height, string output_prefix);
		};


}

#endif 