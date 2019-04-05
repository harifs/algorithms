#\home\user\local\bin\perl -w

$result=diceroll();
print "\nDice Roll result is: $result\n";


# Single Dice Roll - returns anything from 1 to 6
sub diceroll()
{
	$fivetoss=1;
	for($i=0;$i<5;$i++)
	{
		$fivetoss=$fivetoss * cointoss();
	}
	return logb2($fivetoss);
}

# Coin Toss - returns 1 or 2
sub cointoss()
{
 $n=int (1.5+rand());
 return ($n);
}

# Returns log(base2) of M
sub logb2($m)
{
	$m=$_[0];
	$ret=1;
	if($m>1)
	{
		return ($ret++)+logb2($m/2);
	}
	else 
	{
		return ($ret);
	}
}