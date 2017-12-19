using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ShifrXOR
{
    class Program
    {


      //XOR-СЛОЖЕНИЕ ПО МОДУЛЮ 2
        //возращает строку уже зашифрованную 

        //шифровка текста
        public static string Encrypt(byte[] arr, byte[] key)
        {
            byte[] mass = new byte[arr.Length];
            for (int i = 0; i < mass.Length; i++)
            {
                mass[i] = (byte) (arr[i] ^ key[i]); //берется опеределенная ячейка из byte массива, истроки text применяется операция XOR по 5
            }
            //снова преобразовываем byte массив в строку и возвращаем
            return Encoding.Unicode.GetString(mass);
        }

        //дешифровка текста
        public static string Decrypt(string encrypt, byte[] key)
        {
            byte[] arr = Encoding.Unicode.GetBytes(encrypt);//привращение в байт массив
            return Encrypt(arr, key);
        }


        static void Main(string[] args)
        {
            string text = Convert.ToString(Console.ReadLine());
            string key = Convert.ToString(Console.ReadLine()),treukey="";
                for (int i = 0; i < text.Length; i++)
                    treukey += key[i%key.Length];
            byte[] arr = Encoding.Unicode.GetBytes(text);
            byte[] key1 = Encoding.Unicode.GetBytes(treukey);
            string strCrypt=Encrypt(arr, key1); // криптованная строка
            Console.WriteLine(strCrypt);
            Console.WriteLine(Decrypt(strCrypt,key1));
            Console.ReadLine();
        }
    }
}
