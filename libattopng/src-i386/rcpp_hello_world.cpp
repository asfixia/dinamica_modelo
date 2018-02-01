
#include <iostream>
#include <Rcpp.h>
#include "libattopng.h"
using namespace Rcpp;

#define RGBA(r, g, b, a) ((r) | ((g) << 8) | ((b) << 16) | ((a) << 24))

// [[Rcpp::export]]
void rcpp_hello_world(const Rcpp::IntegerMatrix & mat, const CharacterVector & filename) {

	int qntLine = mat.nrow(); //R,G,B,A para cada pixel.
	int qntCol = mat.ncol();
	libattopng_t* png = libattopng_new(qntCol, qntLine, PNG_RGBA);

    int x, y;
	
	for (x = 0; x < qntCol; x++) {
		for (y = 0; y < qntLine; y++) {
			libattopng_set_pixel(png, x, y, mat(y, x));
		}
	}
    libattopng_save(png, (Rcpp::as<std::string>(filename)).c_str());
    libattopng_destroy(png);


    /*CharacterVector x = CharacterVector::create( "foo", "bar" )  ;
    NumericVector y   = NumericVector::create( 0.0, 1.0 ) ;
    List z            = List::create( x, y ) ;*/

    return;
}
