pipeline {
  agent any
  stages {
    stage('Build') {
      steps {
        sh '''rm -rf ../gremlin++
git clone https://github.com/bgamer50/gremlin- -b master-dev ../gremlin++

cppcheck --enable=all --xml --xml-version=2 -I../gremlin++ . 2> cppcheck-result.xml
make components.exe'''
        recordIssues()
        publishCppcheck()
      }
    }

    stage('Test') {
      steps {
        sh '''wget https://snap.stanford.edu/data/facebook_combined.txt.gz
gunzip facebook_combined.txt.gz
./components.exe facebook_combined.txt'''
      }
    }

  }
}