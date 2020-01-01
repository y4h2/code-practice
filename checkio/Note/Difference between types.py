'''
列表解析为[i for i in range(0, 1)], 而(i for i in range(0, 1))为generator, 
通过.next()属性获取下一个元素, 它不像列表解析一次性生成所有元素, 每次调用next生成一个元素;
'''
