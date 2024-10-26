function AddAll(a)
    local start=os.clock()
    local tmp=0
    for i=0,a,1 do
        tmp=tmp+i
    end
    print(string.format("Runtime: %.2f ms", (os.clock()-start)*100))
    return tmp
end

function Sort(a)
    local start=os.clock()
    local size=#a
    for i=1,size,1 do
        for j=i,size,1 do
            if(a[j]<a[i]) then
                local tmp=a[j]
                a[j]=a[i]
                a[i]=tmp
            end
        end
    end
    print(string.format("Runtime: %.2f", (os.clock()-start)*100))
    return a
end

function Guess(x, y)
    math.randomseed(os.time())
    local rnd=math.random(x,y)
    local guesses=0
    local t=false

    while guesses<3 do
        local tmp=io.read("n")
        if tmp==rnd then
            print("Congratulations")
            t=true
            break
        else
            print("Try Again")
        end
        guesses=guesses+1
    end
    if(not t) then print("The Number Was:",rnd) end
end

print("[1] addAll(a)\n[2] sort(a)\n[3] Guessing Game")
local ans = io.read("n")

if ans==1 then
    io.write("Enter Number: ")
    io.write("Final Answer: ", AddAll(io.read("n")))
elseif ans==2 then
    io.write("Enter Array Size: ")
    local t=io.read("n")
    local array = {}
    while t>0 do
        array[t]=io.read("n")
        t=t-1
    end
    array=Sort(array)
    io.write("Sorted Array: [")
    for i=1,#array-1,1 do
        io.write(array[i], ", ")
    end
    io.write(array[#array],"]\n")
elseif ans==3 then
    io.write("Enter Range [x, y]: ")
    local a,b=io.read("n","n")
    Guess(a,b)
else
    print("Invalid Option")
end