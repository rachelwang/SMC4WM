<a href="https://scan.coverity.com/projects/1715">
  <img alt="Coverity Scan Build Status"
       src="https://scan.coverity.com/projects/1715/badge.svg"/>
</a>

``SMC4WM`` is a Statistical Model Checker for some types of probabilistic graphical models. 

Installation
============

Compile
-------

    mkdir build
    cd build
    cmake ../src
    make

Usage
=====

"\nUsage: SMC_wm <testfile> <modelfile> <propertyfile>\n\n"
    "where:\n"
    "      <testfile> is a text file containing a sequence of test specifications, give the path to it;\n"
    "      <modelfile> is the file name and path of the WM model under analysis;\n"
    "      <propertyfile> is the file name and path of properties to be checked.\n\n"
    "Available test specifications: \n\n"
    "Hypothesis test:\n"
    " Lai's test: Lai <theta> <cost per sample>\n"
    " Bayes Factor test: BFT <theta> <threshold T> <alpha> <beta>\n"
    " Sequential Probability Ratio Test: SPRT <theta> <threshold T> <indifference region delta>\n"
    " Bayes Factor test with indifference region: BFTI <theta> <threshold T> <alpha> <beta> <indifference region delta>\n"
    "\n"
    "Estimation methods:\n"
    " Chernoff-Hoeffding bound: CHB <delta> <coverage probability>\n"
    " Bayesian estimation: BEST <delta> <coverage probability> <alpha> <beta>\n"
    "\n"
    "Sampling method:\n"
    " Naive sampling: NSAM <#samples> \n\n"
    "Empty lines and lines beginning with '#' are ignored.\n"
    "";

