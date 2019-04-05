#\home\user\local\bin\perl -w

my $ret=0;

print "\nEnter a number:";
$toss=<>;
chomp($toss);
$result=logb2($toss);
print "\nlog of $toss is $result\n";

sub logb2($m)
{
	$m=$_[0];	
print "\nm=$m; ret=$ret";
	if($m>1)
	{
		$ret++;
		logb2($m/2);
	}
	else
	{
		return $ret;
	}
	
}