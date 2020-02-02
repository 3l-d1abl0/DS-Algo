import ast
_inp_src ="input.txt"
_op_src = "output.txt"

class valueNullError(Exception):
   #Exception class for value Error
   pass

class listError(Exception):
   #List element exception
   pass

class typeError(Exception):
   #data Type Exception
   pass

def ifInt(data):
    data = data.strip()
    try:
        int(data)
    except ValueError as  e:
        return False
    else:
        return True


if __name__=="__main__":

    with open(_inp_src, 'r') as inp:

        #Read the List from file
        base_list = ast.literal_eval(inp.readline())
        #print base_list
        #Make Dictionary from the list
        myset = dict()
        #create frequency of each data
        for ele in base_list:
            if ele in myset:
                myset[ele] +=1
            else:
                myset[ele] =0

        #print myset
        op = open(_op_src,"w")
        for line in inp:
            try:
                if line in ['\n', '\r\n']:#If its a blank Line
                    raise valueNullError({"message":"No input provided!"})
                elif ifInt(line): #checks if data is Integer or Not
                    line = int(line.strip())
                    if line in myset: #checks if data is present in the Dictionary
                        if myset[line] >0: #If Frequency is Greater than One
                            raise listError({"code":myset[line], "message":"Duplicate Entry!", "element":line})
                        else:
                            bit_len = line.bit_length() #get length of binary representation
                            if line+bit_len in myset:
                                op.write('{} is SUPPORTED BY THE NUMBER {}\n'.format(line, line+bit_len))
                            else:
                                op.write('{} is NOT SUPPORTED\n'.format(line))
                    else: #Exception when data not in Dict
                        raise listError({"code":"-1", "message":"Not found in list !", "element":line})
                else: #When data is not a Integer
                    raise typeError({"message":"Not integer type", "element":line.strip()})
            except valueNullError as e:
                op.write('{}\n'.format(e.args[0]["message"]))
                #print(e.args[0]["message"])
            except listError as e:
                if int(e.args[0]["code"])==-1:
                    op.write('Exception : {} is not in the list!\n'.format(e.args[0]["element"]))
                    #print 'Exception : {} is not in the list!'.format(e.args[0]["element"])
                else:
                    op.write('Exception : {} is a duplicate entry!\n'.format(e.args[0]["element"]))
                    #print 'Exception : {} is a duplicate entry!'.format(e.args[0]["element"])
            except typeError as e:
                op.write('Exception : {} is a string!\n'.format(e.args[0]["element"]))
                #print 'Exception : {} is a string!'.format(e.args[0]["element"])

        op.close()
