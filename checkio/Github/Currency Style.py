import re

def checkio(text):
    p = re.compile(r'\$\d{1,3}(?:\.\d{3})*(?:\,\d{0,2})?')
    #print p.findall('$222,100,455.34')
    print text
    for m in p.finditer(text):
        sub_text = m.group()
        if m.end() >= len(text) or not text[m.end()].isdigit():
            #print sub_text
            text = text[:m.start()] + euroStyle(sub_text) + text[m.end():]
    #print text, '\n'
    return text

def euroStyle(text):
    text = text.replace(',', 'a')
    text = text.replace('.', ',')
    text = text.replace('a', '.')
    return text

if __name__ == '__main__':    

    #These "asserts" using only for self-checking and not necessary for auto-testing
    assert checkio("$1.234.567,89") == "$1,234,567.89" , "1st Example"
    assert checkio("$0,89") == "$0.89" , "2nd Example"
    assert checkio("Euro Style = $12.345,67, US Style = $12,345.67") == \
                   "Euro Style = $12,345.67, US Style = $12,345.67" , "European and US"
    assert checkio("Us Style = $12,345.67, Euro Style = $12.345,67") == \
                   "Us Style = $12,345.67, Euro Style = $12,345.67" , "US and European"
    assert checkio("$1.234, $5.678 and $9") == \
                   "$1,234, $5,678 and $9", "Dollars without cents"


# simple solution
import re

def checkio(text):
    reform = lambda match: match.group(0).translate(str.maketrans(',.', '.,'))
    return re.sub('\$\d{1,3}(\.\d{3})*(,\d{2}){,1}(?!\d)', reform, text)
