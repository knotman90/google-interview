project(google-interview NONE)
cmake_minimum_required(VERSION 2.8)
include(cmake/UseLATEX.cmake)


add_latex_document(main.tex  
		INPUTS 	front_cover.tex 
				tree.tex
				ack.tex 
				data_structure.tex
				project_euler.tex
				sorting.tex 
				structure.tex
				competitiveproblems.tex
				hashtable.tex
				dynamicprogramming.tex
		#BIBFILES bib.bib
		IMAGE_DIRS images
		#USE_INDEX
		 )
