#! /bin/sh

init(){
    question=(A B C D E F G H I J K L M N)
    framework="/home/eugene/workspace/CodeTraining/framework.cpp"
    dir=$1
    
    mkdir $dir
    touch "${dir}/summary.md"
    for ((i=0; i<$2; i++))
    do
        cp $framework "${dir}/${question[$i]}.cpp"
    done
    
}

doc(){
    echo "bash ./atcoder.sh init Contest_Name  Num_of_question  : initialize files"
    echo "bash ./atcoder.sh c    Constest_Name Name_of_question : compile source code"
    echo "bash ./atcoder.sh r    Constest_Name Name_of_question : run program"
    echo "bash ./atcoder.sh cr   Constest_Name Name_of_question : compile and run program"
    return 0
}

build(){
    code="$1/$2.cpp"
    out="$1/$2.out"
    g++ -std=c++1z $code -o $out
    c_res=$?
    if ((c_res==0))
    then
        echo "Compile Success"
    fi
    return $c_res
}

run(){
    out="$1/$2.out"
    ./$out
    return 0
}

build_run(){
    build $1 $2
    if (($?==0))
    then
        run $1 $2
    fi
    return 0
}

if (($#<3)) ; then
    doc
fi

cd /home/eugene/workspace/CodeTraining/atcoder

case $3 in
    init)
        init $1 $2
    ;;
    c)
        build $1 $2
    ;;
    r)
        run $1 $2
    ;;
    cr)
        build_run $1 $2
    ;;
    *)
        doc
    ;;
esac