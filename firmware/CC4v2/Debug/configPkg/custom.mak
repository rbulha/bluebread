## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,430 linker.cmd \
  package/cfg/main_p430.o430 \

linker.cmd: package/cfg/main_p430.xdl
	$(SED) 's"^\"\(package/cfg/main_p430cfg.cmd\)\"$""\"D:/Documents and Settings/Rogerio/Meus documentos/workspace/workspace4.2/Bluebread_2452/Debug/configPkg/\1\""' package/cfg/main_p430.xdl > $@
