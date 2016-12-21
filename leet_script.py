import os


# |3|[Same Tree][3]|[C++](003. Same Tree/solution.h)|2014/10/17|Easy|

now = 'MEDIUM/'


class Solution:
    def __init__(self):
        pass





files_name =  os.listdir(now)

# for soluion object container
lister = []

def gets_tring_of_the_file(file_name):
    f = open(now + file_name, 'r', encoding='utf-8')
    res = []
    for line in f.readlines():
        if line.startswith('```'):
            continue
        else:
            res.append(line[:-1])
    return res

f = open('README.md', 'a+', encoding='utf-8')
for filename in files_name:
    try:
        if os.path.isdir(filename): continue

        url = gets_tring_of_the_file(filename)[0][5:-2]
        name_str = url.split('/')[-1].split('-')
        name = ' '.join(name_str)
        numer = filename[:filename.find('[')]

        sl = Solution()
        sl.name = name
        sl.numer = numer
        sl.url = url
        sl.filename = filename

        lister.append(sl)
        
    except:

        print(filename)



lister = sorted(lister, key=lambda obj: int(obj.numer))


for item in lister:
    f.write('|'), f.write(item.numer)
    f.write('|'), f.write('[' + item.name + '](' + item.url + ')')
    f.write('|'), f.write('[Python](' + now + item.filename + ')')
    f.write('|'), f.write(now[:-1]), f.write('|'), f.write('\n')