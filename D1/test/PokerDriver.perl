#!/bin/perl
use strict;

#assuming project and driver have already been compiled
my $numArgs = $#ARGV + 1;  #Number of arguments passed to script
my $numExpected = 0;
my $success = 0;
my $fail = 0; 
my $successAll = 0;

if ($numArgs != $numExpected) {
	print "Please provide exactly $numExpected integer argument(s) to the test script.\n";
	exit 0;
}

my $output = `./pokerdriver`;     
my @array = split (/\n/, $output);  #Split output on new lines

foreach my $line (0..($#array + 1)) {  
	my $currentLine = $array[$line];
	if ($currentLine =~ /FAILURE/) {
		$fail++;            
	} elsif($currentLine =~ /SUCCESS/) {
 		$success++;
	} elsif ($currentLine =~ /ALL/) {
		$successAll++;					
	}
}

if ($fail == 0) {
	print "Success";
} else {
	print "Failure";
}
