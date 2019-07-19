import glob
raw_files = ["." + x.lstrip('.') for x in glob.glob("./*/*/*.h")]
raw_files += ["." + x.lstrip('.') for x in glob.glob("./*/*/*.cpp")]
files = [x + "," for x in raw_files[:-1]] + raw_files[-1:]
f = open("ListOfFiles.tex", "w")
f.write("\\def\ListOfFiles{")
for x in files: f.write(x)
f.write("}")

