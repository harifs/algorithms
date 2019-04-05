#!/user/local/bin/perl

#open(INPUT,"<$ARGV[0]") || die "Could not open the file. Reason: <$!>\n";
#while ($line = <INPUT>)

print "Enter the statement:";
$line=<>;
chomp($line);
@lineArr=split('',$line);
$lenLine=@lineArr;


print "Enter the characters to remove:";
$remch=<>;
chomp($remch);

print "remove: $remch\n";
@charArr = split(//,$remch);
$charLen=@charArr;

print "char arr: @charArr\n";
print "length of charArr is $charLen\n";

%CharHash;

for($i=0;$i<$charLen;$i++)
{
	$CharHash{$charArr[$i]}=1;
}

while(($key,$val)=each(%CharHash))
{
	print "$key=>$val\n";
}
	
for ($i=0;$i<$lenLine;$i++)
{
	unless($CharHash{$lineArr[$i]})
	{
		print "$lineArr[$i]";
	}		
}
print "\n";

exit 0;
