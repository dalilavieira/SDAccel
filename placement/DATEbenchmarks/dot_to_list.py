import sys
import networkx as nx
from graphviz import Source

def create_list(path_dot):

    path_list = 'List/' + path_dot[4:-4] + '.in'

    g = nx.DiGraph(nx.drawing.nx_pydot.read_dot(dot))

    # function: breadth-first search
    # dictionary with the order 
    dict_breadth = {}

    OPEN = []
    # get the node inputs
    cont_no = 0
    for n in g.nodes():
        cont_no += 1
        #print(n)
        if g.in_degree(n) == 0:
            OPEN.insert(0,n)

    CLOSED = []

    count = 0
    cont_edge = 0
    while len(OPEN) > 0 :
        node = OPEN.pop()
        CLOSED.append(node)
        dict_breadth[node] = ""

        lista = []
        lista.append(count)
        for no in list(g.successors(node)):
            lista.append(no)
            cont_edge += 1 
            if no not in OPEN and no not in CLOSED:
                OPEN.insert(0, no)
        
        dict_breadth[node] = lista
        count += 1
    
    arq = open(path_list, 'w')
    arq.write(str(cont_no) + " " + str(cont_edge) + "\n\n")

    for i in dict_breadth :
        no = str(dict_breadth[i][0])
        for j in range(1, len(dict_breadth[i])) :
            arq.write(no + " " + str(dict_breadth[dict_breadth[i][j]][0]) + "\n")

    arq.write("\n")
    # get information opcode on node

    '''
    for i in dict_breadth:
        for n in g.nodes(data=True):
            #print(n)
            if i == n[0]:
                type_node = '2'
                if (n[1]['opcode'] == 'load' or n[1]['opcode'] == 'store'):
                    type_node = '0'
                elif (n[1]['opcode'] == 'output' or n[1]['opcode'] == 'input'):
                    type_node = '1'
                arq.write(str(dict_breadth[i][0]) + " " + type_node + "\n" )
                break
    '''
    arq.close()
    return

def create_list_dfs(path_dot):

    path_list = 'List/' + path_dot[4:-4] + '_dfs.in'

    g = nx.DiGraph(nx.drawing.nx_pydot.read_dot(dot))

    # function: breadth-first search
    # dictionary with the order 
    dict_breadth = {}

    OPEN = []
    # get the node inputs
    cont_no = 0
    for n in g.nodes():
        cont_no += 1
        #print(n)
        if g.in_degree(n) == 0:
            OPEN.insert(0,n)

    CLOSED = []

    count = 0
    cont_edge = 0
    
    while len(OPEN) > 0 :
        node = OPEN.pop()
        CLOSED.append(node)
        dict_breadth[node] = ""

        lista = []
        lista.append(count)
        for no in list(g.successors(node)):
            lista.append(no)
            cont_edge += 1 
            if no not in OPEN and no not in CLOSED:
                OPEN.insert(0, no)
        
        dict_breadth[node] = lista
        count += 1
    
    arq = open(path_list, 'w')
    arq.write(str(cont_no) + " " + str(cont_edge) + "\n\n")

    visit = []
    for i in dict_breadth :
        no = str(dict_breadth[i][0])
        #print(i, dict_breadth[i])

        for j in range(1, len(dict_breadth[i])):
            if [i,dict_breadth[i][j]] not in visit:
                visit.append([i,dict_breadth[i][j]])
    
    OPEN = [visit[0]]
    CLOSED = []
    order = []
    for i in range(len(visit)):
        OPEN = [visit[i]]
        if (len(order) == len(visit)):
            break
        #print(order)
        while len(OPEN) > 0:
            walk = OPEN.pop(0)
            #print(walk)
            if walk not in order: 
                order.append(walk)
            for j in range(len(visit)):
                if walk[1] == visit[j][0] and walk not in CLOSED:
                    OPEN.insert(0,visit[j])
                    CLOSED.append(walk)    
    #print(len(order), len(visit))
    
    for j in range(len(order)) :
        arq.write(str(dict_breadth[order[j][0]][0]) + " " + str(dict_breadth[order[j][1]][0]) + "\n")

    arq.write("\n")
    # get information opcode on node

    '''
    for i in dict_breadth:
        for n in g.nodes(data=True):
            if i == n[0]:
                type_node = '2'
                if (n[1]['opcode'] == 'load' or n[1]['opcode'] == 'store'):
                    type_node = '0'
                elif (n[1]['opcode'] == 'output' or n[1]['opcode'] == 'input'):
                    type_node = '1'
                arq.write(str(dict_breadth[i][0]) + " " + type_node + "\n" )
                break
    '''
    arq.close()
    return

if __name__ == "__main__":

    if len(sys.argv) > 1:
        dot = sys.argv[1]
    else:
        print("python3 create_grid <name.dot>\n")
        exit(0)

    create_list(dot)
    #create_list_dfs(dot)
