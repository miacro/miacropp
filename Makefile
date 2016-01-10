cur_dir=`pwd`
bin=${cur_dir}/bin
build_dir=${cur_dir}/build
parser_dir=${cur_dir}/src/parser
doxygen_config=${cur_dir}/etc/miacropp.doxygen

#options
RELEASE=OFF
AMD64=ON
TEST=ON

ehr_svc:
	@[[ -d ${build_dir} ]] || mkdir -p ${build_dir}
	@cd ${build_dir} && cmake -DMPP_RELEASE=${RELEASE} \
	  -DBUILD_TEST=${TEST} -DCMAKE_CL_64=${AMD64} .. \
	  && make --no-print-directory install

debug:
	@make RELEASE=OFF AMD64=ON TEST=ON ehr_svc
release:
	@make RELEASE=ON AMD64=ON TEST=OFF ehr_svc

rebuild:clean ehr_svc
	@echo "rebuild done"

code_format:
	@${bin}/format-code.sh ${cur_dir}/lib
	@${bin}/format-code.sh ${cur_dir}/test
	@${bin}/format-code.sh ${cur_dir}/src
	@${bin}/format-code.sh ${cur_dir}/miacropp

parser_prepare:parser_generate
	@${bin}/format-code.sh ${parser_dir}
	@echo "parser prepared"

parser_generate:
	@make -C ${parser_dir}

doc:
	@doxygen doxygen_config

clean:
	@[[ ! -f ${build_dir}/install_manifest.txt ]] || \
	  xargs rm < ${build_dir}/install_manifest.txt
	@[[ ! -d ${build_dir} ]] || rm -rf ${build_dir}
	@echo "clean done"
