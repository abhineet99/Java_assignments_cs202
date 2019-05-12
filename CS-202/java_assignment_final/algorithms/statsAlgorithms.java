package algorithms;

import java.io.*;

// The declaration of abstract class for all statistical algos

public abstract class statsAlgorithms{
    public abstract void print(); // in case any sort of output to user is required
    public abstract void value(int inputArr[]); // the func which will return mean, variance etc.
}