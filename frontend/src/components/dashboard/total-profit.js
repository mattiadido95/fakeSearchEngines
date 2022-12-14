import { Avatar, Button, Card, CardContent, Grid, Typography, Divider } from "@mui/material";
import AttachMoneyIcon from "@mui/icons-material/AttachMoney";

export const TotalProfit = (props) => (
  <Card {...props}>
    <CardContent>
      <Grid container spacing={3} sx={{ justifyContent: "space-between" }}>
        <Grid item>
          <Typography color="textSecondary" gutterBottom variant="overline">
            REBUILD INDEX
          </Typography>
          <Divider />
          <Button>START</Button>
        </Grid>
        <Grid item>
          {/* <Avatar
            sx={{
              backgroundColor: "primary.main",
              height: 56,
              width: 56,
            }}
          >
            <AttachMoneyIcon />
          </Avatar> */}
        </Grid>
      </Grid>
    </CardContent>
  </Card>
);
