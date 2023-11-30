void testFace(IFace* fc) {
			IFace* a[3] = { fc, fc->clone(), fc->clone() };// đã tạo bộ nhớ nhưng lại chưa xóa trước khi kết thúc hàm.
			for(int i=0; i<3; i++) {
				a[i]->show();
			}
			cout << “The same 3 lines?”;
			delete a[1];
			delete a[2];
			return;
		}
		Thêm mã vào lớp EyesFace như sau:
		.....
		public:
			static int COUNT_OBJECT;
			EyedFace(const string& sh, const int& e){{
				.....
				COUNT_OBJECT++;
			}
			~EyedFace(){
				........
				COUNT_OBJECT--;
			}
		};
		// trong file .cpp
		int EyedFace::COUNT_OBJECT=0;
		// trong main()
		int main(){
			........
			cout<<"So doi tuong thuoc EyedFace"<<EyedFace::COUNT_OBJECT<<endl;
			return 0;
		}