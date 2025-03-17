
# 查看打开游标
    select count(*) from v$open_cursor;
# 创建dba用户
    create user border identified by oraclexxxx;
    grant connect,resource to border;
    select count(*) from v$open_cursor;
    grant dba to border
# 解锁用户
    alter user border accaut unlock;
# 查看日志空间
    sqlplus /nolog 
    connect /as sysdba
    select * from V$FLASH_RECOVERY_AREA_USAGE;
    select sum(percent_space_used)*3/100 from v$flash_recovery_area_usage;
    ALTER SYSTEM SET DB_RECOVERY_FILE_DEST_SIZE=8g;
    show parameter recover;
    
    cat deletearchivelog.sh
#!/bin/bash
###################
. /etc/profile
. ~/.bash_profile
##################
echo `date +%F_%T` >> /home/oracle/deletearchivelog.log
rman target / <<EOF
crosscheck archivelog all;
delete noprompt expired archivelog all;
DELETE noprompt ARCHIVELOG ALL COMPLETED BEFORE "SYSDATE-1";
exit;
EOF
    
    



