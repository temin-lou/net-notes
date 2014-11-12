euca_conf --register-cluster --partition cluster01 --host 10.10.11.158 --component cc_158
euca_conf --register-walrusbackend --partition walrus --host 10.10.11.158 --component walrus_158
euca_conf --register-nodes "10.10.11.158"
> cloud-cluster.log; > cloud-debug.log;> cloud-error.log;> cloud-exhaust.log ; > cloud-output.log ;> cloud-requests.log;> httpd-cc_error_log;> startup.log;
