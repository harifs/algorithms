#!/usr/local/bin/perl

print "Enter the string: ";
$str=<>;
chomp($str);

@strArr = split('',$str);
%strHash;

$strLen = @strArr;

print "str = $str \n";
print "strArr = @strArr \n";
print "length of array = $strLen \n";

for ($i=0;$i<$strLen; $i++)
{	
	$strHash{$strArr[$i]} = ($strHash{$strArr[$i]}+1);	
}

#Print the Hash
while (($key,$val)=each(%strHash))
{
	print "$key=>$val\n"
}

for ($i=0;$i<$strLen;$i++)
{
	if($strHash{$strArr[$i]} eq 1)
	{
		print "$strArr[$i] is the character\n";
		exit 0;
	}
}

print "All characters are repeated!\n";
exit 1;