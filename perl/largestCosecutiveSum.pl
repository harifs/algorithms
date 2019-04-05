#!\user\local\bin\perl -w

print "\nTesting: All the elements of the array";
@arr=(2,-3,1,2,4,4,-1,2,-8,6);

$len=@arr;
$sum=$arr[0];
$tmpsum=$arr[0];

for ($i=1;$i<$len;$i++)
{
	if($arr[$i]>=0 && $tmpsum>=0)
	{
		$tmpsum+=$arr[$i];
	}
	else
	{
		if ($tmpsum>$sum)
		{
			$sum=$tmpsum;
		}
		$tmpsum=$arr[$i];
	}	
	print "\ntmpsum: $tmpsum ; arr[i]= $arr[$i] ; sum=$sum";
}
if ($tmpsum>$sum)
{
	$sum=$tmpsum;
}
print "\nlargest consecutive sum: $sum";



