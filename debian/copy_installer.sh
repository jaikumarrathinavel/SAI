if [[ x"$1" =~ x"v2" ]]
then
   echo "Copy python-saithriftv2.install as python-saithrift.install"
   cp ./debian/installerFiles/python-saithriftv2.install ./debian/python-saithrift.install
else
   if test -n "lsb_release -a | grep bullseye"
   then
      echo "Copy python-saithriftv1-bullseye.install as python-saithrift.install"
      cp ./debian/installerFiles/python-saithriftv1-bullseye.install ./debian/python-saithrift.install
   else
      echo "Copy python-saithriftv1.install as python-saithrift.install"
      cp ./debian/installerFiles/python-saithriftv1.install ./debian/python-saithrift.install
   fi   
fi
