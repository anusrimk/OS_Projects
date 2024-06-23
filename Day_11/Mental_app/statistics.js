import React from 'react';
import { View, Text, Button, StyleSheet } from 'react-native';

const App = () => {
  return (
    <View style={styles.container}>
      <View style={styles.statsContainer}>
        <Text style={styles.statTitle}>Heart Rate</Text>
        <Text style={styles.stat}>96 bpm</Text>
      </View>
      <View style={styles.statsContainer}>
        <Text style={styles.statTitle}>SPO2</Text>
        <Text style={styles.stat}>96%</Text>
      </View>
      <View style={styles.statsContainer}>
        <Text style={styles.statTitle}>Stress Rate</Text>
        <Text style={styles.stat}>43%</Text>
      </View>
      <View style={styles.buttonContainer}>
        <Button title="Stress Levels Report" onPress={() => console.log('Stress levels report pressed!')} />
        <Button title="Sleep Report" onPress={() => console.log('Sleep report pressed!')} />
      </View>
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
  },
  statsContainer: {
    flexDirection: 'row',
    justifyContent: 'space-between',
    alignItems: 'center',
    margin: 10,
  },
  statTitle: {
    fontSize: 18,
    fontWeight: 'bold',
  },
  stat: {
    fontSize: 16,
  },
  buttonContainer: {
    flexDirection: 'row',
    justifyContent: 'space-between',
    width: '80%',
  },
});

export default App;
