
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

The command line:

" SMC_wm <testfile> <modelfile> <propertyfile>", where
    
    "      <testfile> is a text file containing a sequence of test specifications, give the path to it;"
    
    "      <modelfile> is the file name and path of the WM model under analysis;"
    
    "      <propertyfile> is the file name and path of properties to be checked."
    
Available test specifications:

    Hypothesis test:
    
    " Lai's test: Lai <theta> <cost per sample>"
    
    " Bayes Factor test: BFT <theta> <threshold T> <alpha> <beta>"
    
    " Sequential Probability Ratio Test: SPRT <theta> <threshold T> <indifference region delta>"
    
    " Bayes Factor test with indifference region: BFTI <theta> <threshold T> <alpha> <beta> <indifference region delta>"
    
    Estimation methods:
    
    " Chernoff-Hoeffding bound: CHB <delta> <coverage probability>"
    
    " Bayesian estimation: BEST <delta> <coverage probability> <alpha> <beta>"
    
    Sampling method:
    
    " Naive sampling: NSAM <#samples>"
    

