#!/usr/bin/perl

#------------------------------
# daemon process sample, written by charlee, 2006/10/12
#

use strict;
use POSIX 'setsid';

our $USER = 'lijian';
our $GROUP = 'lijian';

#------------------------------
# child process to be created by daemon
sub child_process {
    # do some work here
}


#------------------------------
# create daemon process

# 1. fork() so the parent can exit, returns control to shell.
exit if fork;

# 2. setsid() to become a process group and session group leader.
&setsid();

# 3. fork() again so the parent (session group leader) can exit.
exit if fork;

# 4. (OPTIONAL) chdir('/') to ensure our daemon doesn't keep any directory in use.
chdir '/';

# 5. (OPTIONAL) umask() so we have complete control over the permissions of anything we write.
umask 022;

# 6. close() fds 0, 1, and 2.
close STDIN;
close STDOUT;
close STDERR;

# 7. redirect fds 0, 1, and 2 to /dev/null
open STDIN, '/dev/null';
open STDOUT, '>/dev/null';
open STDERR, '>/dev/null';

# 8. change to daemon user and group.
&sudo($USER, $GROUP);

# 9. ignore SIGCHLD signal to avoid zombie processes
$SIG{CHLD} = 'IGNORE';

# 10. start main loop.
while(1) {
    my $pid = fork;
    if ($pid == 0) {
        &child_process();
        exit;
    } else {
        sleep 1;
    }
}

# main end

# function to change user and group
sub sudo {
    my ($user, $group) = @_;
    my $uid = (getpwnam($user))[2];
    my $gid = (getgrnam($group))[2];
    ($(, $)) = ($gid, "$gid $gid");
    ($<, $>) = ($uid, $uid);
}    

__END__
