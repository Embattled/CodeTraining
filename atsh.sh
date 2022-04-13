#! /bin/sh

DIR="$( cd "$( dirname "$0" )" && pwd )"
FRAMEWORK=$DIR"/framework.cpp"
ATCODER=$DIR"/atcoder/"


init(){
    question=(A B C D E F G H I J K L M N)
    dir=$ATCODER$1
    
    mkdir $dir
    touch "${dir}/summary.md"
    for ((i=0; i<$2; i++))
    do
        cp $FRAMEWORK "${dir}/${question[$i]}.cpp"
    done
    
}

doc(){
    echo "bash ./atsh.sh Contest_Name  Num_of_question  init : initialize files"
    echo "bash ./atsh.sh Constest_Name Name_of_question c    : compile source code"
    echo "bash ./atsh.sh Constest_Name Name_of_question r    : run program"
    echo "bash ./atsh.sh Constest_Name Name_of_question cr   : compile and run program"
    return 0
}

build(){
    code=$ATCODER"$1/$2.cpp"
    out=$ATCODER"$1/$2.out"
    g++ -std=c++1z $code -o $out
    c_res=$?
    if ((c_res==0))
    then
        echo "Compile Success"
    fi
    return $c_res
}

run(){
    out=$ATCODER"$1/$2.out"
    $out
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
    exit
fi


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