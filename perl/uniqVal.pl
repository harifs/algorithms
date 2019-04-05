#!/usr/local/bin/perl


$_nputFile = $ARGV[0];
$_nputFile1 = $ARGV[1];

%Total=();
$DistinctErr="";

if ($_nputFile eq "")
{
	print stderr "Usage : uniqVal.pl <file1 contain lot of values > <find values of file2 in file1>\n";
	exit 1;
}

open( INPUT_FILE, "<$_nputFile" ) || die "Cannot open input file $_nputFile. Cause <$!>\n";

$line1=1;

while ($line = <INPUT_FILE>)
{
	chop;

        # print the line just read without change

        chop;
	$DistinctErr = "$line";

	$DistinctErr =~ s/^[ ]*//;
        $DistinctErr =~ s/[ ]*$//;
	$DistinctErr =~ s/^[\t]*//;
        $DistinctErr =~ s/[\t]*$//;
	chop $DistinctErr;
	
	$Total{$DistinctErr}=$line1;

	$DistinctErr = "";
	$line1++;
} 

close(INPUT_FILE);

$found="found";
$not_found="notfound";
#print "Here\n";
open( INPUT_FILE1, "<$_nputFile1" ) || die "Cannot open input file $_nputFile. Cause <$!>\n";
open( FOUND, ">$ARGV[1].$found" ) || die "Cannot open input file $found. Cause <$!>\n";
open( NOT_FOUND, ">$ARGV[1].$not_found" ) || die "Cannot open input file $notfound. Cause <$!>\n";

$count=0;
while ($line = <INPUT_FILE1>)
{
	chop;

        # print the line just read without change

        chop;
	$DistinctErr = "$line";

	$DistinctErr =~ s/^[ ]*//;
        $DistinctErr =~ s/[ ]*$//;
	$DistinctErr =~ s/^[\t]*//;
        $DistinctErr =~ s/[\t]*$//;
	chop $DistinctErr;

	if($Total{$DistinctErr})
	{
		$count++;
		#printf FOUND  ("Found : %20s in rec # %d\n",$DistinctErr, $Total{$DistinctErr});
		#if ( $count == 15 )
		#{
			#print FOUND "\n";
			#$count=0;
		#}
		printf FOUND  "$DistinctErr\n";
	}
	else
	{
		print NOT_FOUND "$DistinctErr\n"
	}
		
	$DistinctErr = "";
} 

close(NOT_FOUND);
close(FOUND);
close(INPUT_FILE1);
