import sys
import networkx as nx
from graphviz import Source
import random as rand
import numpy as np

def create_id(g, EDGE):
    
    dic_id = {}

    OPEN = []
    # get the node inputs
    cont_no = 0
    for n in g.nodes():
        cont_no += 1
        if g.in_degree(n) == 0:
            OPEN.insert(0,n)

    CLOSED = []

    count = 0
    while len(OPEN) > 0 :
        node = OPEN.pop()
        CLOSED.append(node)
        dic_id[node] = count

        for no in list(g.successors(node)):
            EDGE.append([node, no]) 
            if no not in OPEN and no not in CLOSED:
                OPEN.insert(0, no)
        count += 1 

    #for no in dic_id:
    #    print(dic_id[no], no)

    return dic_id, count, len(EDGE)

def dfs_zigzag(g, LIST, VISITED, NEW_EDGE, left):
    
    while len(LIST) > 0:
        if left == 1:
            node, direction = LIST.pop(0) # remove stack
        else:
            node, direction = LIST.pop()

        if direction == 'IN':
            for n in list(g.predecessors(node)):
                if n not in VISITED:
                    NEW_EDGE.append([n, node])
                    #print("%s -> %s %s" %(n, node, direction))
                    VISITED.append(n)
                    LIST.insert(0, [n, 'IN']) # simulated recursive
                    if g.out_degree(n) > 1:
                        LIST.insert(0, [n, 'OUT']) # change to other direction
                        break
                    if g.in_degree(n) > 1:
                        LIST.insert(0, [node, 'IN'])
                        #print("adiciona %s IN" % n)
                    
        else: # direction OUT
            for n in list(g.successors(node)):
                if n not in VISITED:
                    NEW_EDGE.append([node, n])
                    #print("%s -> %s %s" %(node, n, direction))
                    VISITED.append(n)
                    LIST.insert(0, [n, 'OUT']) # simulated recursive
                    if g.in_degree(n) > 1:
                        #if g.out_degree(n) > 1:
                        #    LIST.insert(0, [node, 'OUT'])
                        LIST.insert(0, [n, 'IN']) # change to other direction
                        #print("inverte direcao para IN")
                        break
                    if g.out_degree(n) > 1:
                        LIST.insert(0, [n, 'OUT'])
        

def create_list_zigzag(g, dic_id, EDGE, N_NODE, count, name_graph):

    OUTS = []
    
    # get the node inputs
    for n in g.nodes():
        if g.out_degree(n) == 0:
            OUTS.append(n)
    
    rand.seed()
    rand.shuffle(OUTS)
    
    NEW_EDGE = []
    EDGE_LIST = []
    LIST = []
    VISITED = []
    
    for no in OUTS:
        if no not in VISITED:
            VISITED.append(no)
            LIST.insert(0, [no, 'IN']) # insert stack
            dfs_zigzag(g, LIST, VISITED, NEW_EDGE, rand.randint(0, 1))

    for i in range(len(EDGE)):
        if EDGE[i] not in NEW_EDGE:
            NEW_EDGE.append(EDGE[i])
    
        EDGE_LIST.append(str(dic_id[NEW_EDGE[i][0]]))
        EDGE_LIST.append(str(dic_id[NEW_EDGE[i][1]]))

    arq = open("List_several/"+name_graph+"/"+name_graph+"_"+str(count)+'.in', "w")

    #for i in range(0,len(EDGE_LIST),2):
    #   arq.write(EDGE_LIST[i]+" "+EDGE_LIST[i+1]+"\n")

    arq.write(str(N_NODE) +" "+ str(len(EDGE_LIST)//2) + "\n\n")
    
    #for i in range(len(EDGE_LIST)-1,0,-2):
    #   arq.write(EDGE_LIST[i-1]+" "+EDGE_LIST[i]+"\n")

    for i in range(0,len(EDGE_LIST),2):
        arq.write(EDGE_LIST[i]+" "+EDGE_LIST[i+1]+"\n")
        
    arq.close()

def create_list_largura(g, dic_id, N_NODE, N_EDGE, count, name_graph):

    EDGE_LIST = []
    OPEN = []
    for n in g.nodes():
        if g.in_degree(n) == 0:
            OPEN.insert(0,n)

    rand.seed()
    rand.shuffle(OPEN)

    CLOSED = []
    while len(OPEN) > 0 :
        node = OPEN.pop()
        CLOSED.append(node)
        list_temp = []
        for no in list(g.successors(node)):
            list_temp.append([str(dic_id[node]), str(dic_id[no])])
            if no not in OPEN and no not in CLOSED:
                OPEN.insert(0, no)
        
        # create order in percurse different
        rand_int = np.full(len(list_temp), 0, dtype=int)
        for i in range(len(list_temp)):
            rand_int[i] += i

        rand.seed()
        rand.shuffle(rand_int)

        for i in range(len(list_temp)):
            EDGE_LIST.append(list_temp[rand_int[i]][0])
            EDGE_LIST.append(list_temp[rand_int[i]][1])

    arq = open("List_several/"+name_graph+"/"+name_graph+"_"+str(count)+'.in', "w")

    arq.write(str(N_NODE) +" "+ str(N_EDGE) + "\n\n")

    #for i in range(len(EDGE_LIST)-1,0,-2):
    #   arq.write(EDGE_LIST[i-1]+" "+EDGE_LIST[i]+"\n")

    for i in range(0,len(EDGE_LIST),2):
        arq.write(EDGE_LIST[i]+" "+EDGE_LIST[i+1]+"\n")

    arq.close()
        
def create_list_profundidade(g, dic_id, N_NODE, N_EDGE, count, name_graph):
    
    EDGE_LIST = []
    OPEN = []
    for n in g.nodes():
        if g.in_degree(n) == 0:
            OPEN.append(n)

    rand.seed()
    rand.shuffle(OPEN)

    CLOSED = []
    while len(OPEN) > 0 :
        node = OPEN.pop(0)
        CLOSED.append(node)
        list_temp = []
        for no in list(g.successors(node)):
            list_temp.append([str(dic_id[node]), str(dic_id[no])])
            if no not in OPEN and no not in CLOSED:
                OPEN.insert(0, no)

        # create order in percurse different
        rand_int = np.full(len(list_temp), 0, dtype=int)
        for i in range(len(list_temp)):
            rand_int[i] += i

        rand.seed()
        rand.shuffle(rand_int)

        for i in range(len(list_temp)):
            EDGE_LIST.append(list_temp[rand_int[i]][0])
            EDGE_LIST.append(list_temp[rand_int[i]][1])
    
    arq = open("List_several/"+name_graph+"/"+name_graph+"_"+str(count)+'.in', "w")

    arq.write(str(N_NODE) +" "+ str(N_EDGE) + "\n\n")

    #for i in range(len(EDGE_LIST)-1,0,-2):
    #   arq.write(EDGE_LIST[i-1]+" "+EDGE_LIST[i]+"\n")

    for i in range(0,len(EDGE_LIST),2):
        arq.write(EDGE_LIST[i]+" "+EDGE_LIST[i+1]+"\n")

    arq.close()

if __name__ == "__main__":

    if len(sys.argv) > 2:
        dot = sys.argv[1]
        name_graph = sys.argv[2]
        print(name_graph)
    else:
        print("python3 dot_to_list_several.py <name.dot> <name>\n")
        exit(0)
    
    g = nx.DiGraph(nx.drawing.nx_pydot.read_dot(dot))

    EDGE = []
    dic_id, N_NODE, N_EDGE = create_id(g, EDGE)

    print(str(N_NODE) + " " + str(N_EDGE) + "\n")

    tam = 0
    for i in range(tam, tam+34):
        create_list_zigzag(g, dic_id, EDGE, N_NODE, i, name_graph)
    tam += 34
    
    for i in range(tam, tam+34):
        create_list_largura(g, dic_id, N_NODE, N_EDGE, i, name_graph)
    tam += 34

    for i in range(tam, tam+34):
        create_list_profundidade(g, dic_id, N_NODE, N_EDGE, i, name_graph)
