public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        this.requestWindowFeature(Window.FEATURE_NO_TITLE);
        setContentView(R.layout.activity_main);
        final EditText web = (EditText) findViewById(R.id.wy);
        final TextView textView = (TextView)findViewById(R.id.xs);
        Button button = (Button)findViewById(R.id.find);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                new Thread(){
                    @Override
                    public void run() {
                        // TODO Auto-generated method stub
                        try{
                            String path = web.getText().toString().trim();
                            URL url = new URL(path);
                            HttpURLConnection con1= (HttpURLConnection)url.openConnection();
                            String location = con1.getHeaderField("location");
                            url = new URL(location);
                            HttpURLConnection con = (HttpURLConnection)url.openConnection();
                            con.setRequestMethod("POST");
                            con.setConnectTimeout(5000);
                            int code=con.getResponseCode();
                            System.out.println(code);
                            if(code==200){
                                InputStream in= con.getInputStream();
                                System.out.println("------zhu");
                                final String content = Cookie.readStream(in);
                               runOnUiThread(new Runnable(){
                                    @Override
                                    public void run() {
                                        textView.setText(content);
                                    }
                                });
                                in.close();
                            }
                            else{
                                System.out.println("服务器忙");
                            }
                        }catch(Exception e){
                            System.out.println("404");
                        }

                    }

                }.start();
            }

        });
    }
}
public class Cookie {
    public static String readStream(InputStream in) throws IOException {
        //ByteArrayOutputStream by = new ByteArrayOutputStream();
        StringBuffer by = new StringBuffer();
        int len =-1;
        byte [] buffer = new byte[1024];
        while((len=in.read(buffer))!=-1){
            by.append(new String(buffer,0,len));
        }
        in.close();

        String content = by.toString();
        return content;
    }
}


