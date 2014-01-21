#!/usr/bin/perl
use strict;
use POSIX 'setsid';


# create daemon process
sub become_daemon {
    die "Can't fork" unless defined (my $child = fork);
    exit 0 if $child;
    setsid();
    close STDIN;
    close STDOUT;
    close STDERR;

    open STDIN, 'test.log';
    open STDOUT, '>test.log';
    open STDERR, '>test.log';
    chdir '/';
    umask(0);
    $ENV{PATH} = "/bin:/sbin:/usr/bin:/usr/sbin";
    $SIG{CHLD} = 'IGNORE';

    return $$;
}

&become_daemon();
while(1) {
    my $pid = fork;
    if ($pid == 0) {
        my $t = time;
        my ($sec, $min, $hour, $day, $month, $year) = (localtime($t))[0,1,2,3,4,5,6];
        # open(FH, ">>", "test.txt");
        $t = time;
        ($sec, $min, $hour, $day, $month, $year) = (localtime($t))[0,1,2,3,4,5,6];
        $year += 1900;
        print "$year $month-$day $hour:$min:$sec\n";
        #usleep 200;
        #sleep 2;
        #close(FH);
        exit;
    } else {
        select(undef, undef, undef, 0.25);
    }
}



