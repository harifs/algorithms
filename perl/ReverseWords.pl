#!\user\local\bin\perl

print "Enter the sentence:";
$line=<> || die "Input Error <$!>";
chomp($line);
$reverse=join(' ',reverse(split(/ /,$line)));

print "Reversed words: $reverse\n";
