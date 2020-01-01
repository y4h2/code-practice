def flatten(a):
    if a:
        result = {}
        for i in a:
            if isinstance(a[i], dict):
                temp = flatten(a[i])
                if temp:
                    for j in temp:
                        result['%s/%s' % (i, j)] = temp[j]
                else:
                    result[i] = ''
            else:
                result[i] = a[i]
        return result
    else:
        return None
