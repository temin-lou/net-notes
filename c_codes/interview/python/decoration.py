def synchronized(lock):  
    """锁同步装饰方法 
    ！lock必须实现了acquire和release方法 
    """  
                                        
def sync_with_lock(func):  
    def new_func(*args, **kwargs):  
        lock.acquire()  
        try:  
            return func(*args, **kwargs)  
        finally:  
            lock.release()  
        new_func.func_name = func.func_name  
        new_func.__doc__ = func.__doc__  
        return new_func  
    return sync_with_lock  

@synchronized(__locker) 
def update(data):  
"""更新计划任务"""  
    tasks = self.get_tasks()  
    delete_task = None  
    for task in tasks:  
        if task[PLANTASK.ID] == data[PLANTASK.ID]:  
            tasks.insert(tasks.index(task), data)  
            tasks.remove(task)  
            delete_task = task  
        r, msg = self._refresh(tasks, delete_task)  
        return r, msg, data[PLANTASK.ID]  
